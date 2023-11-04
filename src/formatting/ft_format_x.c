/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:15:39 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:45:45 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_format_x(t_arg *arg, va_list *args)
{
	unsigned int	nbr;
	t_signed_size			count;
	t_signed_size			len;
	int				is_upper;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	nbr = va_arg(*args, unsigned int);
	is_upper = 0;
	if (arg->type == 'X')
		is_upper = 1;
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
	{
		len = ft_max(ft_hexlen(nbr), arg->width);
		count += ft_print_hex(nbr, arg->flag_hash, len, is_upper);
		return (count);
	}
	len = ft_hexnlen(nbr, arg->flag_hash, arg->precision);
	if (arg->flag_minus)
		count += ft_print_hex(nbr, arg->flag_hash, arg->precision, is_upper);
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_hex(nbr, arg->flag_hash, arg->precision, is_upper);
	return (count);
}
