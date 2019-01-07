/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:48:31 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/07 16:03:27 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

_Bool			init_map(t_map *a_map, int dim)
{
	int	i;
	int j;

	a_map->dim = dim;
	if (!(a_map->map = (char**)malloc((a_map->dim + 1) * sizeof(char*))))
		return (0);
	i = -1;
	while (++i < a_map->dim + 1)
		if(!(a_map->map[i] = (char*)malloc((a_map->dim + 1) * sizeof(char))))
			return (0);
	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
			MAP[i][j] = '.';
	}
	i = -1;
	j = -1;
	while (++i < dim)
		MAP[i][dim] = '\0';
	while (++j <= dim)
		MAP[dim][j] = '\0';
	return (1);
}	

int		sqrt_up(int n)
{
	int	root;

	root = 2;
	while (root * root < n)
		root++;
	return (root);
}

int				find_top_bottom(t_tetro tetro, _Bool top)
{
	int	i;

	i = (top) ? 0 : 3;
	while (!strchr(tetro.array[i], '#'))
		i = (top) ? i + 1 : i - 1;
	return (i);
}

int				find_left_edge(t_tetro tetro)
{
	int	i;
	int	j;
	int	left_edge;

	i = -1;
	j = -1;
	left_edge = 3;
	while (++j < 3)
		while (++i < 3)
			if (tetro.array[i][j] == '#')
				if (j < left_edge)
					left_edge = j;
	return (left_edge);
}

int				find_right_edge(t_tetro tetro)
{
	int	i;
	int	j;
	int	right_edge;

	i = 4;
	j = 4;
	right_edge = 0;
	while (--j > 0)
		while (--i > 0)
			if (tetro.array[i][j] == '#')
				if (j > right_edge)
					right_edge = j;
	return (right_edge);
}

