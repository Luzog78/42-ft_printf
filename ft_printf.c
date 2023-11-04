/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:40:44 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 03:43:38 by ysabik           ###   ########.fr       */
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
	printf("  -->  length: %lld\n", arg->length);
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
