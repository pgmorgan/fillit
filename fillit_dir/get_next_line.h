/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:27:08 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/02 15:29:26 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# define BUFF_SIZE 10
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int const fd, char **line);

#endif
