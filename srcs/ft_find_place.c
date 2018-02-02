/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:35:42 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 18:35:53 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_find_place(t_map *p, int *a, int *b)
{
	int		x;
	int		y;
	char	letter;

	if (p->player == 'O')
		letter = p->player;
	else
		letter = 'X';
	y = 0;
	while (y < p->h)
	{
		x = 0;
		while (x < p->w)
		{
			if (ft_check_place(p, x, y, letter))
				if (((*a) == 0 && (*b) == 0) || (ft_len(p) &&
				ft_len_btw((*a), (*b), p) > ft_len_btw(y, x, p)))
				{
					(*a) = y;
					(*b) = x;
				}
			x++;
		}
		y++;
	}
}
