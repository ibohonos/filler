/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:36:06 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 18:36:14 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_map(t_map *p)
{
	char	tmp;
	int		a;
	int		b;

	a = 0;
	b = 0;
	ft_find_place(p, &a, &b);
	ft_printf("%d %d\n", a, b);
	ft_free_arr(p->map);
	ft_free_arr(p->tetri);
	tmp = p->player;
	ft_init_map(p);
	p->player = tmp;
}
