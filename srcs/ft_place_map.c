/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:36:06 by ibohonos          #+#    #+#             */
/*   Updated: 2018/02/06 01:11:09 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_find_tetri_pos(t_map *p)
{
	int i;
	int j;

	i = 0;
	while (i < p->y)
	{
		j = 0;
		while (j < p->x)
		{
			if (p->tetri[i][j] == '*')
			{
				if (p->tetri_y == -1)
					p->tetri_y = i;
				if (p->tetri_x == -1 || p->tetri_x > j)
					p->tetri_x = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_place_map(t_map *p)
{
	char	tmp;
	char	tmp2;
	int		a;
	int		b;

	a = 0;
	b = 0;
	ft_find_tetri_pos(p);
	ft_find_place(p, &a, &b);
	ft_printf("%d %d\n", a, b);
	ft_free_arr(p->map);
	ft_free_arr(p->tetri);
	tmp = p->player;
	tmp2 = p->enemy;
	ft_init_map(p);
	p->player = tmp;
	p->enemy = tmp2;
}
