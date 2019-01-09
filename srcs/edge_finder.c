/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:48:31 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/09 15:02:12 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

void			print_map(t_map *a_map)
{
	int i;

	i = -1;
	while(a_map->map[++i][0])
		printf("%s\n", a_map->map[i]);
	printf("\n");
}


void			free_map(t_map *a_map, int dim)
{
	while (dim + 1)
	{
		free(a_map->map[dim]);
		dim--;
	}
	free(a_map->map);
	free(a_map);
	return ;
}

_Bool			new_map(t_map *a_map, int dim)
{
	int	i;
	int j;

	a_map->dim = dim;
	if (!(a_map->map = (char**)malloc((dim + 1) * sizeof(char*))))
		return (0);
	i = -1;
	while (++i < dim + 1)
		if(!(a_map->map[i] = (char*)malloc((dim + 1) * sizeof(char))))
			return (0);
	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
			a_map->map[i][j] = '.';
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
	for (int i = 0; i < 4 ; i++)
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

	tetro[3].array = NULL;

	return (1);
}
