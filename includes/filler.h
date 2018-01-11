/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:26:18 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 11:51:42 by ibohonos         ###   ########.fr       */
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

void			filler(char *line, t_map *p);

#endif
