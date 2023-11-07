/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_lx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:15:39 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/07 02:03:21 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_setup(t_arg *arg, va_list *args,
	unsigned long *nbr, t_signed_size *count)
{
	if (arg->width == -2)
	{
		arg->width = va_arg(*args, int);
		if (arg->width < 0)
		{
			arg->width = ft_abs(arg->width);
			arg->flag_minus = 1;
		}
	}
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	*nbr = va_arg(*args, unsigned long);
	*count = 0;
}

t_signed_size	ft_format_lx(t_arg *arg, va_list *args)
{
	unsigned long	nbr;
	t_signed_size	count;
	t_signed_size	len;

	ft_setup(arg, args, &nbr, &count);
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
	{
		len = ft_max(ft_hexlen(nbr, arg->flag_hash), arg->width);
		if (arg->flag_hash && nbr)
			len -= 2;
		count += ft_print_hex(nbr, arg->flag_hash, len, arg->type);
		return (count);
	}
	len = ft_hexnlen(nbr, arg->flag_hash, arg->precision);
	if (arg->flag_minus)
		count += ft_print_hex(nbr, arg->flag_hash, arg->precision, arg->type);
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_hex(nbr, arg->flag_hash, arg->precision, arg->type);
	return (count);
}
