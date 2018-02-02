/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:26:18 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/01 17:57:13 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "ft_printf.h"
#include "get_next_line.h"

typedef struct	s_map
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			row;
	int			done;
	int			save_x;
	int			save_y;
	char		player;
	char		**map;
	char		**tetri;
}				t_map;

void			ft_place_line_tetri(char *line, t_map *p);
void			ft_place_line_map(char *line, t_map *p);
void			ft_find_place(t_map *p, int *a, int *b);
void			ft_find_player(char *line, t_map *p);
void			ft_find_tetri(char *line, t_map *p);
void			ft_find_map(char *line, t_map *p);
void			filler(char *line, t_map *p);
void			ft_free_arr(char **arr);
void			ft_place_map(t_map *p);
void			ft_init_map(t_map *p);
int				ft_check_place(t_map *p, int x, int y, char letter);
int				ft_find_spase(t_map *p, int i, int j);
int				ft_len_btw(int i, int j, t_map *p);
int				ft_len(t_map *p);

#endif
