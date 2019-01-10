/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_tetrominos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:56:04 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/10 12:56:11 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			print_tetro_array(t_tetro *tetro, int num_tetri)
{
	int	i;
	int j;

	i = 0;
	while (i < num_tetri)
	{
		j = 0;
		while (j < 4)
		{
			printf("%s\n", tetro[i].array[j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int				find_top_bottom(t_tetro tetro, _Bool top)
{
	int	i;

	i = (top) ? 0 : 3;
	while (i >= 0 && i < 4 && !ft_strchr_range(tetro.array[i], 'A', 'Z'))
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
	while (++j < 4)
	{
		while (++i < 4)
			if (tetro.array[i][j] != '.' && tetro.array[i][j] != '\0')
				if (j < left_edge)
					left_edge = j;
		i = -1;
	}
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
	while (--j >= 0)
	{
		while (--i >= 0)
			if (tetro.array[i][j] != '.' && tetro.array[i][j] != '\0')
				if (j > right_edge)
					right_edge = j;
		i = 4;
	}
	return (right_edge);
}

_Bool		retrieve_tetro_array(t_tetro *tetro)
{
	for (int i = 0; i < 8 ; i++)
		if (!(tetro[i].array = (char**)malloc(5 * sizeof(char*))))
			return (0);

	tetro[0].array[0] = strdup("....");
	tetro[0].array[1] = strdup("..AA");
	tetro[0].array[2] = strdup("...A");
	tetro[0].array[3] = strdup("...A");
	tetro[0].tl.x = find_left_edge(tetro[0]);
	tetro[0].tl.y = find_top_bottom(tetro[0], 1);
	tetro[0].br.x = find_right_edge(tetro[0]);
	tetro[0].br.y = find_top_bottom(tetro[0], 0);
	tetro[0].id = 'A';

	tetro[1].array[0] = strdup("....");
	tetro[1].array[1] = strdup("....");
	tetro[1].array[2] = strdup("BB..");
	tetro[1].array[3] = strdup("BB..");
	tetro[1].tl.x = find_left_edge(tetro[1]);
	tetro[1].tl.y = find_top_bottom(tetro[1], 1);
	tetro[1].br.x = find_right_edge(tetro[1]);
	tetro[1].br.y = find_top_bottom(tetro[1], 0);
	tetro[1].id = 'B';

	tetro[2].array[0] = strdup("..C.");
	tetro[2].array[1] = strdup("..C.");
	tetro[2].array[2] = strdup("..CC");
	tetro[2].array[3] = strdup("....");
	tetro[2].tl.x = find_left_edge(tetro[2]);
	tetro[2].tl.y = find_top_bottom(tetro[2], 1);
	tetro[2].br.x = find_right_edge(tetro[2]);
	tetro[2].br.y = find_top_bottom(tetro[2], 0);
	tetro[2].id = 'C';

	tetro[3].array[0] = strdup("DDDD");
	tetro[3].array[1] = strdup("....");
	tetro[3].array[2] = strdup("....");
	tetro[3].array[3] = strdup("....");
	tetro[3].tl.x = find_left_edge(tetro[3]);
	tetro[3].tl.y = find_top_bottom(tetro[3], 1);
	tetro[3].br.x = find_right_edge(tetro[3]);
	tetro[3].br.y = find_top_bottom(tetro[3], 0);
	tetro[3].id = 'D';

	tetro[4].array[0] = strdup("EEEE");
	tetro[4].array[1] = strdup("....");
	tetro[4].array[2] = strdup("....");
	tetro[4].array[3] = strdup("....");
	tetro[4].tl.x = find_left_edge(tetro[4]);
	tetro[4].tl.y = find_top_bottom(tetro[4], 1);
	tetro[4].br.x = find_right_edge(tetro[4]);
	tetro[4].br.y = find_top_bottom(tetro[4], 0);
	tetro[4].id = 'E';

	tetro[5].array[0] = strdup("FFFF");
	tetro[5].array[1] = strdup("....");
	tetro[5].array[2] = strdup("....");
	tetro[5].array[3] = strdup("....");
	tetro[5].tl.x = find_left_edge(tetro[5]);
	tetro[5].tl.y = find_top_bottom(tetro[5], 1);
	tetro[5].br.x = find_right_edge(tetro[5]);
	tetro[5].br.y = find_top_bottom(tetro[5], 0);
	tetro[5].id = 'F';

	tetro[6].array[0] = strdup("GGGG");
	tetro[6].array[1] = strdup("....");
	tetro[6].array[2] = strdup("....");
	tetro[6].array[3] = strdup("....");
	tetro[6].tl.x = find_left_edge(tetro[6]);
	tetro[6].tl.y = find_top_bottom(tetro[6], 1);
	tetro[6].br.x = find_right_edge(tetro[6]);
	tetro[6].br.y = find_top_bottom(tetro[6], 0);
	tetro[6].id = 'G';

	tetro[7].array = NULL;

	return (1);
}
