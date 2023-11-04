/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:14:37 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:45:41 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_format_s(t_arg *arg, va_list *args)
{
	char	*str;
	t_signed_size	count;
	t_signed_size	len;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	str = va_arg(*args, char *);
	if (!str)
	{
		if (arg->precision < 0 || arg->precision >= 6)
			str = "(null)";
		else
			str = "";
	}
	if (arg->precision < 0)
		len = ft_str_len(str);
	else
		len = ft_min(ft_str_len(str), arg->precision);
	if (arg->flag_minus)
		count += ft_print_n_str(str, len);
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_n_str(str, len);
	return (count);
}
