/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:29:30 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/10 12:41:59 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(void)
{
	t_map	*a_map;
	t_tetro	*tetro;
	int		dim;
	int		num_tetri = 7;

	dim = sqrt_up(num_tetri * 4);

	if (!(a_map = (t_map*)malloc(sizeof(t_map))))
		return (-1);
	if (!(new_map(a_map, dim)))
		return (-1);

	if (!(tetro = (t_tetro*)malloc((num_tetri+1)*sizeof(t_tetro))))
		return (-1);
	if (!(retrieve_tetro_array(tetro)))
		return (-1);

	print_tetro_array(tetro, num_tetri);
	grow_map(a_map, tetro);
	print_map(a_map);

	return (0);
}

_Bool			collision(t_map *a_map, t_tetro *tetro, t_node pn)
{
	int	n;
	int	m;

	n = -1;
	while (tetro->tl.y + (++n) < 4)
	{	
		m = -1;
		while (tetro->tl.x + (++m) < 4)
			if (tetro->array[tetro->tl.y + n][tetro->tl.x + m] != '.' 
				&& a_map->map[pn.y + n][pn.x + m] != '.')
				return (1);
	}
	return (0);
}

_Bool			grow_map(t_map	*a_map, t_tetro *tetro)
{
	int	dim;

	while (!recursive_fit(a_map, tetro, 0))
	{
		dim = a_map->dim;	
		free_map(a_map, dim);
		if (!(new_map(a_map, ++dim)))
			return (0);
	}
	return (1);
}

int				recursive_fit(t_map *a_map, t_tetro *tetro, size_t ind)
{
	t_node	pn;

	if (tetro[ind].array == NULL)
		return (1);
	pn.y = 0;
	while (pn.y + tetro[ind].br.y < a_map->dim)
	{
		pn.x = 0;
		while (pn.x + tetro[ind].br.x < a_map->dim)
		{
			if (!collision(a_map, &tetro[ind], pn))
			{
				add_piece(a_map, &tetro[ind], pn);
				if (recursive_fit(a_map, tetro, ++ind))
					return (1);
				remove_piece(a_map, &tetro[ind], pn);
			}
			pn.x++;
		}
		pn.y++;
	}
	return (0);
}
