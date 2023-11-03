/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzog <luzog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:40:44 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/02 23:45:25 by luzog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(t_arg *arg)
{
	printf("Printing arg:\n");
	printf("  -->  flag_minus: %d\n", arg->flag_minus);
	printf("  -->  flag_plus: %d\n", arg->flag_plus);
	printf("  -->  flag_space: %d\n", arg->flag_space);
	printf("  -->  flag_zero: %d\n", arg->flag_zero);
	printf("  -->  flag_hash: %d\n", arg->flag_hash);
	printf("  -->  width: %d\n", arg->width);
	printf("  -->  precision: %d\n", arg->precision);
	printf("  -->  size: %d\n", arg->size);
	printf("  -->  type: %c\n", arg->type);
	printf("  -->  length: %d\n", arg->length);
}

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
	t_arg	*arg;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			arg = ft_parse(format);
			if (arg)
			{
				print_arg(arg);
				count += ft_format(arg, &args);
				format += arg->length;
				free(arg);
			}
		}
		else
		{
			count += ft_print_chr(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
