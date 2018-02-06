/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:33:20 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/06 01:10:41 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init_map(t_map *p)
{
	p->x = 0;
	p->y = 0;
	p->w = 0;
	p->h = 0;
	p->row = -1;
	p->done = 0;
	p->save_x = 0;
	p->save_y = 0;
	p->tetri_x = -1;
	p->tetri_y = -1;
	p->enemy_x = 0;
	p->enemy_y = 0;
	p->player = 0;
	p->enemy = 0;
	p->map = NULL;
	p->tetri = NULL;
}
