/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 20:37:05 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/11 11:59:38 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int	ft_newline_or_eof_ind(char *store_fd)
{
	unsigned int i;

	i = 0;
	while (store_fd[i] != '\n' && store_fd[i] != '\0')
		i++;
	return (i);
}

/*
**	LINE 35
**	ft_strchr(store_fd, '\n') will always be a smaller or equal string to
**	store_fd, hence we can use ft_strcpy (no overflow risk).
*/

static char			*ft_overwrite_store_with_remainder(char *store_fd)
{
	if (ft_strchr(store_fd, '\n'))
	{
		ft_strcpy(store_fd, ft_strchr(store_fd, '\n') + 1);
		return (store_fd);
	}
	if (ft_newline_or_eof_ind(store_fd) > 0)
	{
		ft_strcpy(store_fd, ft_strchr(store_fd, '\0'));
		return (store_fd);
	}
	return (NULL);
}

/*
**	NOTES	**
**
**	LINE 65
**	MacOSX has a max fd of 256.
**	Store is a non-Null array of (initially) NULL char* pointers.
**	Default value of each pointer in array is NULL because Statically declared.
**
**	LINE 72
**	store[fd] == NULL unless fd has been opened and read to store[fd].
**	Hence, !store[fd] is TRUE the first time get_next_line is called for each fd
**
**	LINE 74
**	ft_strchr returns a pointer to the first instance of char c in char *str.
**	or NULL pointer if c not found.
*/

int					get_next_line(int const fd, char **line)
{
	static char		*store[257];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				read_val;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (store[fd] == NULL && (store[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(store[fd], '\n')) &&
			(read_val = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_val] = '\0';
		tmp = store[fd];
		if (!(store[fd] = ft_strnjoin(tmp, buff, read_val)))
			return (-1);
		free(tmp);
	}
	*line = ft_strsub(store[fd], 0, ft_newline_or_eof_ind(store[fd]));
	if (ft_overwrite_store_with_remainder(store[fd]) == NULL)
		return (0);
	return (1);
}
