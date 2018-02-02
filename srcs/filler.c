/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:33:44 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/02 16:08:50 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(char *line, t_map *p)
{
	ft_init_map(p);
	while (get_next_line(0, &line) > 0)
	{
		if (p->player == 0)
			ft_find_player(line, p);
		if (!p->w && !p->h)
			ft_find_map(line, p);
		else if (p->row >= 0 && p->row < p->h)
			ft_place_line_map(line, p);
		if (p->row >= p->h)
			ft_find_tetri(line, p);
		else if (p->row >= 0 && p->row < p->y)
			ft_place_line_tetri(line, p);
		if (p->done == 1)
			ft_place_map(p);
		ft_strdel(&line);
	}
}
