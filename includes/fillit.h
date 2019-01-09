/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:49:53 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/09 15:02:32 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# define	TETR		tetro->array
# define	TR			tetro->tl

# define	TETRO		tetro.array
# define	TL			tetro.tl

# define	MAP			a_map->map
# define	PN			a_map->pn

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>		//Don't forget to delete this and all printf's
# include "libft/libft.h"

typedef struct		s_node
{
	int		y;
	int		x;
}					t_node;

typedef struct		s_tetro
{
	char	**array;
	char	id;
	t_node	tl;					//top left edge of tetro
	t_node	br;					//bottom right edge of tetro
}					t_tetro;

typedef struct		s_map
{
	char	**map;
	t_node	pn;					//present node
	int		dim;
}					t_map;

int				find_right_edge(t_tetro tetro);
int				find_left_edge(t_tetro tetro);
int				find_top_bottom(t_tetro tetro, _Bool top);
int				sqrt_up(int n);
_Bool			new_map(t_map *a_map, int dim);
_Bool			retrieve_tetro_array(t_tetro *tetro);
_Bool			collision(t_map *a_map, t_tetro *tetro);
_Bool			grow_map(t_map  *a_map, t_tetro *tetro);
int				recursive_fit(t_map *a_map, t_tetro *tetro, size_t id);
void			print_tetro_array(t_tetro *tetro, int num_tetri);
void			print_map(t_map *a_map);
void			free_map(t_map *a_map, int dim);
void			add_piece(t_map *a_map, t_tetro *tetro);
void			remove_piece(t_map *a_map, t_tetro *tetro);

#endif