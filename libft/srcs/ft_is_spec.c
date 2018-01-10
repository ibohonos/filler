/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 23:24:39 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/02 23:39:22 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_spec(t_struct *p)
{
	if (p->spec_l != 0 || p->spec_ll != 0 || p->spec_h != 0 || p->spec_hh != 0)
		return (1);
	else if (p->spec_j != 0 || p->spec_z != 0)
		return (1);
	return (0);
}