/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:35:22 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/06 01:32:10 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		ft_check_place(t_map *p, int x, int y)
{
	int i;
	int j;
	int k;

	// dprintf(2, "ft_check_place x = %d\ty = %d\n", x, y);
	k = 0;
	i = p->tetri_y;
	y -= i;
	x -= p->tetri_x;
	if (y < 0 || x < 0)
		return (0);
	while (i < p->y)
	{
		j = p->tetri_x;
		while (j < p->x)
		{
			if (p->tetri[i][j] == '*')
			{
				// dprintf(2, "ft_check_place end %d\n", i);
				if (y + i >= p->h || x + j >= p->w)
				{
					return (0);
				}
				if (p->map[y + i][x + j] == p->player)
					k++;
				else if (p->map[y + i][x + j] == p->enemy)
					return (0);
			}
			// if (p->map[y + i][x + j] == p->player && p->tetri[i][j] == '*')
			// 	k++;
			// else if (p->map[y + i][x + j] != '.' && p->tetri[i][j] == '*')
			// 	k = 2;
			j++;
		}
		i++;
	}
	return (k);
}
