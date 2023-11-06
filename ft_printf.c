/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:40:44 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/06 23:12:47 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_arg(const char **format,
	va_list *args, int *has_invalid_arg)
{
	int		count;
	t_arg	*arg;

	count = 0;
	arg = ft_parse(*format + 1);
	if (arg)
	{
		if (arg->type == '\0')
			*has_invalid_arg = 1;
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
	int		has_invalid_arg;

	if (!format)
		return (-1);
	count = 0;
	has_invalid_arg = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!*(format + 1) && !has_invalid_arg)
				return (-1);
			count += ft_handle_arg(&format, &args, &has_invalid_arg);
		}
		else
			count += ft_print_chr(*format);
		format++;
	}
	va_end(args);
	return (count);
}
