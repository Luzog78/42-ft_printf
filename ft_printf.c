/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:40:44 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 04:27:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
