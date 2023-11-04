/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:15:09 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:45:35 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_format_d(t_arg *arg, va_list *args)
{
	t_signed_size	nbr;
	t_signed_size	count;
	t_signed_size	len;
	char	spacing;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	nbr = va_arg(*args, int);
	spacing = '\0';
	if (arg->flag_plus)
		spacing = '+';
	else if (arg->flag_space)
		spacing = ' ';
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
	{
		len = ft_max(ft_nbrlen(nbr, spacing), arg->width);
		if (nbr < 0 || spacing)
			len--;
		count += ft_print_nbr(nbr, spacing, len);
		return (count);
	}
	len = ft_nbrnlen(nbr, spacing, arg->precision);
	if (arg->flag_minus)
		count += ft_print_nbr(nbr, spacing, arg->precision);
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_nbr(nbr, spacing, arg->precision);
	return (count);
}
