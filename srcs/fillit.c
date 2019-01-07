/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:29:30 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/07 16:30:50 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				main(void)
{
	t_map	*a_map;
	int		dim;
	int		num_tetri = 3;

	dim = sqrt_up(num_tetri * 4);
	if (!(a_map = (t_map*)malloc(sizeof(t_map))))
		return (-1);
	if (!init_map(a_map, dim))
		return (-1);

	t_tetro	*tetro;
	if (!(tetro = (t_tetro*)malloc((num_tetri+1)*sizeof(t_tetro))))
		return (-1);
	for (int i = 0; i < 4 ; i++)
		if (!(tetro[i].array = (char**)malloc(5 * sizeof(char*))))
			return (-1);

	tetro[0].array[0] = strdup("....");
	tetro[0].array[1] = strdup("....");
	tetro[0].array[2] = strdup("..A.");
	tetro[0].array[3] = strdup(".AAA");
	tetro[0].tl.x = 1;
	tetro[0].tl.y = 2;
	tetro[0].br.x = 3;
	tetro[0].br.y = 3;

	tetro[1].array[0] = strdup("....");
	tetro[1].array[1] = strdup("....");
	tetro[1].array[2] = strdup("..B.");
	tetro[1].array[3] = strdup(".BBB");
	tetro[1].tl.x = 1;
	tetro[1].tl.y = 2;
	tetro[1].br.x = 3;
	tetro[1].br.y = 3;

	tetro[2].array[0] = strdup("....");
	tetro[2].array[1] = strdup("....");
	tetro[2].array[2] = strdup("..C.");
	tetro[2].array[3] = strdup(".CCC");
	tetro[2].tl.x = 1;
	tetro[2].tl.y = 2;
	tetro[2].br.x = 3;
	tetro[2].br.y = 3;
}

_Bool			collision(t_map *a_map, t_tetro tetro)
{
	int	n;
	int	m;

	n = -1;
	m = -1;
	while (TL.y + (++n) < 4)
		while (TL.x + (++m) < 4)
			if (TETRO[TL.y + n][TL.x + m] != '.' && MAP[PN.y + n][PN.x + m] != '.')	
				return (1);
	return (0);
}

