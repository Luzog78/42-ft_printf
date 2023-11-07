/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:15:25 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/07 02:03:21 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_setup(t_arg *arg, va_list *args,
	unsigned int *nbr, t_signed_size *count)
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
	*nbr = va_arg(*args, unsigned int);
	*count = 0;
}

t_signed_size	ft_format_u(t_arg *arg, va_list *args)
{
	unsigned int	nbr;
	t_signed_size	count;
	t_signed_size	len;

	ft_setup(arg, args, &nbr, &count);
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
	{
		len = ft_max(ft_unbrlen(nbr), arg->width);
		count += ft_print_unbr(nbr, len);
		return (count);
	}
	len = ft_unbrnlen(nbr, arg->precision);
	if (arg->flag_minus)
		count += ft_print_unbr(nbr, arg->precision);
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_unbr(nbr, arg->precision);
	return (count);
}
