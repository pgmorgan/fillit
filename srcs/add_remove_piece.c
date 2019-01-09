/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:19:35 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/09 15:02:16 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			add_piece(t_map *a_map, t_tetro *tetro)
{
	int m;
	int n;

	n = 0;
	while (tetro->tl.y + n <= tetro->br.y)
	{
		m = 0;
		while (tetro->tl.x + m <= tetro->br.x)
		{
			if (a_map->map[a_map->pn.y + n][a_map->pn.x + m] == '.')
				a_map->map[a_map->pn.y + n][a_map->pn.x + m] 
				= tetro->array[tetro->tl.y + n][tetro->tl.x + m];
			m++;
		}
		n++;
	}
}

void			remove_piece(t_map *a_map, t_tetro *tetro)
{
	int m;
	int n;

	n = 0;
	while (tetro->tl.y + n <= tetro->br.y)
	{
		m = 0;
		while (tetro->tl.x + m <= tetro->br.x)
		{
			if (tetro->array[tetro->tl.y + n][tetro->tl.x + m] == tetro->id)
				a_map->map[a_map->pn.y + n][a_map->pn.x + m] = '.';
			m++;
		}
		n++;
	}
}
