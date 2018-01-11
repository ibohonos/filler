/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:37:43 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 18:37:50 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_find_map(char *line, t_map *p)
{
	char **tmp;

	tmp = ft_strsplit(line, ' ');
	if (ft_strcmp(tmp[0], "Plateau") == 0)
	{
		p->w = ft_atoi(tmp[2]);
		p->h = ft_atoi(tmp[1]);
		p->map = (char **)malloc(sizeof(char *) * p->h + 1);
		p->row = 0;
	}
	ft_free_arr(tmp);
}
