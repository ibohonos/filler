/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_zx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:20:42 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/09 14:14:09 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_zx(size_t type_zx, t_struct *p, int b)
{
	char *c;

	if (p->sharp != -1 && type_zx > 0 && b == 0)
	{
		ft_putstr("0x");
		if (p->width == -1 && p->precision == -1)
			p->ret_len += 2;
	}
	else if (p->sharp != -1 && type_zx > 0 && b == 1)
	{
		ft_putstr("0X");
		if (p->width == -1 && p->precision == -1)
			p->ret_len += 2;
	}
	p->buffer = ft_unsigned_itoa_base(type_zx, 16);
	c = p->buffer;
	if (b == 1)
		p->buffer = ft_strupper(c);
	else
		p->buffer = ft_unsigned_itoa_base(type_zx, 16);
	ft_strdel(&c);
	ft_putstr(p->buffer);
	p->ret_len += ft_strlen(p->buffer);
	ft_strdel(&p->buffer);
}