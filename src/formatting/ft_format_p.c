/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:14:53 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 04:11:55 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_format_p(t_arg *arg, va_list *args)
{
	void			*ptr;
	t_signed_size	count;
	t_signed_size	len;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	ptr = va_arg(*args, void *);
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
	{
		len = ft_max(ft_ptrlen(ptr, 0), arg->width) - 2;
		if ((arg->flag_plus || arg->flag_space) && ptr)
		{
			if (arg->flag_plus)
				count += ft_print_chr('+');
			else if (arg->flag_space)
				count += ft_print_chr(' ');
			len--;
		}
		count += ft_print_ptr(ptr, len);
		return (count);
	}
	len = ft_ptrlen(ptr, arg->precision);
	if ((arg->flag_plus || arg->flag_space) && ptr)
		len++;
	if (arg->flag_minus)
	{
		if (arg->flag_plus && ptr)
			count += ft_print_chr('+');
		else if (arg->flag_space && ptr)
			count += ft_print_chr(' ');
		count += ft_print_ptr(ptr, arg->precision);
	}
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
	{
		if (arg->flag_plus && ptr)
			count += ft_print_chr('+');
		else if (arg->flag_space && ptr)
			count += ft_print_chr(' ');
		count += ft_print_ptr(ptr, arg->precision);
	}
	return (count);
}
