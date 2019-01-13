/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_tetros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:58:37 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/13 22:32:05 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_shape_y_axis(t_tetro *tetro)
{
	int		i;
	int		j;
	int		edges;

	edges = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetro->array[i][j] == tetro->id)
			{
				if (i != 0)
					if (tetro->array[i - 1][j] == tetro->id)
						++edges;
				if (i != 3)
					if (tetro->array[i + 1][j] == tetro->id)
						++edges;
			}
		}
	}
	return (edges);
}

int			check_shape_x_axis(t_tetro *tetro)
{
	int		i;
	int		j;
	int		edges;

	edges = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetro->array[i][j] == tetro->id)
			{
				if (j != 0)
					if (tetro->array[i][j - 1] == tetro->id)
						++edges;
				if (j != 3)
					if (tetro->array[i][j + 1] == tetro->id)
						++edges;
			}
		}
	}
	return (edges);
}

_Bool		count_hashtags(t_tetro *tetro)
{
	int	hashtag_count;
	int	i;
	int j;

	hashtag_count = 0;
	i = -1;
	while (++i < 4)
	{
		if (ft_strlen(tetro->array[i]) != 4)
			return (0);
		j = -1;
		while (++j < 4)
		{
			if (tetro->array[i][j] == tetro->id)
				hashtag_count++;
			else if (tetro->array[i][j] != '.')
				return (0);
		}
	}
	if (hashtag_count != 4)
		return (0);
	if (check_shape_y_axis(tetro) + check_shape_x_axis(tetro) < 6)
		return (0);
	return (1);
}

_Bool		count_tetros(char *filename, int *num_tetri)
{
	char	*str;
	int		fd;
	int		line_count;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &str) == 1)
	{
		line_count++;
		ft_strdel(&str);
	}
	close(fd);
	if ((line_count + 1) % 5 != 0)
		return (0);
	*num_tetri = (line_count + 1) / 5;
	return (1);
}

_Bool		check_tetro_chars(t_tetro *tetro, int num_tetri)
{
	int		i;
	int		j;
	int		k;
	char	id;

	id = 'A';
	i = -1;
	while (++i < num_tetri)
	{
		tetro[i].id = id++;
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				if (!(tetro[i].array[j][k] == '#' ||
					tetro[i].array[j][k] == '.'))
					return (0);
			}
			ft_chr_replace(tetro[i].array[j], '#', tetro[i].id);
		}
	}
	return (1);
}

_Bool		check_empty_line_and_error(char *str, int j)
{
	if (ft_strcmp(str, "") == 0 && j != 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

int			check_empty_line_and_continue(char *str, int j)
{
	if (ft_strcmp(str, "") == 0 && j == 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

_Bool		copy_tetri(char *filename, int *num_tetri, t_tetro *tetro, int fd)
{
	char	*str;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	i = -1;
	while (++i < *num_tetri)
	{
		j = 0;
		while (j < 4)
		{
			if (get_next_line(fd, &str) == -1)
				return (0);
			if (check_empty_line_and_continue(str, j) == 1)
				continue;
			if (check_empty_line_and_error(str, j) == 1)
				return (error_msg());
			if (!(tetro[i].array[j] = ft_strdup(str)))
				return (0);
			free(str);
			j++;
		}
	}
	close(fd);
	return (1);
}

void		find_tetro_edges(t_tetro *tetro)
{
	tetro->tl.x = find_left_edge(*tetro);
	tetro->tl.y = find_top_bottom(*tetro, 1);
	tetro->br.x = find_right_edge(*tetro);
	tetro->br.y = find_top_bottom(*tetro, 0);
}

t_tetro		*recover_tetros(char *filename, int *num_tetri)
{
	int		i;
	t_tetro	*tetro;

	if (!count_tetros(filename, num_tetri))
		return ((t_tetro*)error_msg());
	if (!(tetro = (t_tetro*)malloc((*num_tetri + 1) * sizeof(t_tetro))))
		return (NULL);
	i = -1;
	while (++i < *num_tetri)
		if (!(tetro[i].array = (char**)malloc(4 * sizeof(char*))))
			return (NULL);
	if (!(copy_tetri(filename, num_tetri, tetro, 0)))
		return (NULL);
	if (!(check_tetro_chars(tetro, *num_tetri)))
		return ((t_tetro*)error_msg());
	i = -1;
	while (++i < *num_tetri)
	{
		if (!count_hashtags(&(tetro[i])))
			return ((t_tetro*)error_msg());
		find_tetro_edges(&(tetro[i]));
	}
	tetro[i].array = NULL;
	return (tetro);
}

