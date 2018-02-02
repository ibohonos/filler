/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:34:55 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 18:35:04 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_len(t_map *p)
{
	int		i;
	int		j;
	char	letter;

	if (p->player == 'O')
		letter = 'X';
	else
		letter = 'O';
	i = 0;
	while (i < p->h)
	{
		j = 0;
		while (j < p->w)
		{
			if (p->map[i][j] == letter && ft_find_spase(p, i, j))
			{
				p->save_x = j;
				p->save_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
