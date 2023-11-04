/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:04:56 by luzog             #+#    #+#             */
/*   Updated: 2023/11/04 02:45:48 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_format(t_arg *arg, va_list *args)
{
	if (arg->type == 'c')
		return (ft_format_c(arg, args));
	else if (arg->type == 's')
		return (ft_format_s(arg, args));
	else if (arg->type == 'p')
		return (ft_format_p(arg, args));
	else if (arg->type == 'd' || arg->type == 'i')
		return (ft_format_d(arg, args));
	else if (arg->type == 'u')
		return (ft_format_u(arg, args));
	else if (arg->type == 'x' || arg->type == 'X')
		return (ft_format_x(arg, args));
	else if (arg->type == '%')
		return (ft_print_chr('%'));
	ft_print_chr('%');
	return (0);
}
