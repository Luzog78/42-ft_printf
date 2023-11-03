/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzog <luzog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:04:56 by luzog             #+#    #+#             */
/*   Updated: 2023/11/02 23:53:46 by luzog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_c(t_arg *arg, va_list *args)
{
	char	c;
	int		count;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	c = va_arg(*args, int);
	
	if (arg->precision >= 0)
	
	if (arg->flag_minus)
		count += ft_print_chr(c);
	while (arg->width > 1)
	{
		if (arg->flag_zero)
			count += ft_print_chr('0');
		else
			count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_chr(c);
	return (count);
}

int	ft_format(t_arg *arg, va_list *args)
{
	if (arg->type == 'c')
		return (ft_format_c(arg, args));
	/*else if (arg->type == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (arg->type == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (arg->type == 'd' || arg->type == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (arg->type == 'u')
		return (ft_print_unbr(va_arg(args, unsigned int)));
	else if (arg->type == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (arg->type == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (arg->type == '%')
		return (ft_print_chr('%'));*/
	return (0);
}