/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:14:09 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 05:34:01 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_setup(t_arg *arg, va_list *args, char *c, t_signed_size *count)
{
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	*c = va_arg(*args, int);
	*count = 0;
}

t_signed_size	ft_format_c(t_arg *arg, va_list *args)
{
	char			c;
	t_signed_size	count;

	ft_setup(arg, args, &c, &count);
	if (arg->flag_minus)
		count += ft_print_chr(c);
	while (arg->width > 1)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_chr(c);
	return (count);
}
