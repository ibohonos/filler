/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:35:22 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 18:35:30 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_place(t_map *p, int x, int y, char letter)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	if ((p->w - x - p->x) < 0 || (p->h - y - p->y) < 0)
		return (0);
	while (k < p->y)
	{
		j = 0;
		while (j < p->x)
		{
			if (p->map[y + k][x + j] == letter && p->tetri[k][j] == '*')
				i++;
			else if (p->map[y + k][x + j] != '.' && p->tetri[k][j] == '*')
				i = 2;
			j++;
		}
		k++;
	}
	if (i == 1)
		return (1);
	return (0);
}
