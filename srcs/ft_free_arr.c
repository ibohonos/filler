/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:32:44 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 18:32:58 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		ft_strdel(&arr[i++]);
	free(arr);
	arr = NULL;
}
