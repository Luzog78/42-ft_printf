/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:40:44 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/02 09:58:13 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_print_chr(va_arg(args, int)));
	else if (*format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (*format == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_print_unbr(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (*format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (*format == '%')
		return (ft_print_chr('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_parse_format(format, args);
		}
		else
			count += ft_print_chr(*format);
		format++;
	}
	va_end(args);
	return (count);
}
