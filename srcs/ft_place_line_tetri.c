/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_line_tetri.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:36:24 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 18:36:32 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_line_tetri(char *line, t_map *p)
{
	p->tetri[p->row] = ft_strdup(line);
	p->row++;
	if (p->row == p->y)
	{
		p->row = 0;
		p->done = 1;
	}
}
