/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_line_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:36:46 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 18:36:54 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_line_map(char *line, t_map *p)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[1] && !(ft_strcmp(arr[0], "Plateau") == 0))
	{
		p->map[p->row] = ft_strdup(arr[1]);
		p->row++;
	}
	ft_free_arr(arr);
}
