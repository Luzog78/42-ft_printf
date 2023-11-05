/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:40:44 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 05:41:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_arg(const char **format, va_list *args)
{
	int		count;
	t_arg	*arg;

	count = 0;
	arg = ft_parse(*format);
	if (arg)
	{
		count += ft_format(arg, args);
		*format += arg->length;
		free(arg);
	}
	return (count);
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
			count += ft_handle_arg(&format, &args);
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
