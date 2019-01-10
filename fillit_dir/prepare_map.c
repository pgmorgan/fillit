/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:54:41 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/10 12:55:38 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		a_map->map[i][dim] = '\0';
	while (++j <= dim)
		a_map->map[dim][j] = '\0';
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
