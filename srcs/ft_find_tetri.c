/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:37:07 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 18:37:14 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_find_tetri(char *line, t_map *p)
{
	char **tmp;

	tmp = ft_strsplit(line, ' ');
	if (ft_strcmp(tmp[0], "Piece") == 0)
	{
		p->x = ft_atoi(tmp[2]);
		p->y = ft_atoi(tmp[1]);
		p->tetri = (char **)malloc(sizeof(char *) * p->y + 1);
		p->row = 0;
	}
	ft_free_arr(tmp);
}
