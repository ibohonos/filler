/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_zd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:20:42 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/07 15:51:49 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_zd(long type_zd, t_struct *p)
{
	p->buffer = ft_itoa_base(type_zd, 10);
	ft_putstr(p->buffer);
	p->ret_len += ft_strlen(p->buffer);
	ft_strdel(&p->buffer);
}
