/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:35:42 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/06 01:48:57 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	ft_find_place(t_map *p, int *a, int *b)
{
	int		x;
	int		y;

	y = 0;
	while (y < p->h)
	{
		x = 0;
		while (x < p->w)
		{
			if (ft_check_place(p, x, y) == 1)
				if ((*a == 0 || *b == 0))
				{
					(*a) = y - p->tetri_y;
					(*b) = x - p->tetri_x;
				}
			x++;
		}

		y++;
	}
	// dprintf(2, "y = %d\tx = %d\n", *a, *b);
}
