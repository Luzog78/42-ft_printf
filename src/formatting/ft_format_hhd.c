/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hhd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:15:09 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 06:12:55 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_setup(t_arg *arg, va_list *args, char *nbr, t_signed_size *count)
{
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	*nbr = (char) va_arg(*args, int);
	*count = 0;
}

static t_signed_size	ft_zero_filling(t_arg *arg, char nbr, char spacing)
{
	t_signed_size	len;

	len = ft_max(ft_nbrlen(nbr, spacing), arg->width);
	if (nbr < 0 || spacing)
		len--;
	return (ft_print_nbr(nbr, spacing, len));
}

t_signed_size	ft_format_hhd(t_arg *arg, va_list *args)
{
	char			nbr;
	t_signed_size	count;
	t_signed_size	len;
	char			spacing;

	ft_setup(arg, args, &nbr, &count);
	spacing = '\0';
	if (arg->flag_plus)
		spacing = '+';
	else if (arg->flag_space)
		spacing = ' ';
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
		return (count + ft_zero_filling(arg, nbr, spacing));
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
