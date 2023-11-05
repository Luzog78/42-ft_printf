/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:04:56 by luzog             #+#    #+#             */
/*   Updated: 2023/11/05 06:54:21 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_signed_size	ft_format_decimal(t_arg *arg, va_list *args)
{
	if (arg->size == 4)
		return (ft_format_lld(arg, args));
	else if (arg->size == 3)
		return (ft_format_ld(arg, args));
	else if (arg->size == 2)
		return (ft_format_hd(arg, args));
	else if (arg->size == 1)
		return (ft_format_hhd(arg, args));
	return (ft_format_d(arg, args));
}

static t_signed_size	ft_format_unsigned(t_arg *arg, va_list *args)
{
	if (arg->size == 4)
		return (ft_format_llu(arg, args));
	else if (arg->size == 3)
		return (ft_format_lu(arg, args));
	else if (arg->size == 2)
		return (ft_format_hu(arg, args));
	else if (arg->size == 1)
		return (ft_format_hhu(arg, args));
	return (ft_format_u(arg, args));
}

static t_signed_size	ft_format_hexadecimal(t_arg *arg, va_list *args)
{
	if (arg->size == 4)
		return (ft_format_llx(arg, args));
	else if (arg->size == 3)
		return (ft_format_lx(arg, args));
	else if (arg->size == 2)
		return (ft_format_hx(arg, args));
	else if (arg->size == 1)
		return (ft_format_hhx(arg, args));
	return (ft_format_x(arg, args));
}

static t_signed_size	ft_format_octal(t_arg *arg, va_list *args)
{
	if (arg->size == 4)
		return (ft_format_llo(arg, args));
	else if (arg->size == 3)
		return (ft_format_lo(arg, args));
	else if (arg->size == 2)
		return (ft_format_ho(arg, args));
	else if (arg->size == 1)
		return (ft_format_hho(arg, args));
	return (ft_format_o(arg, args));
}

t_signed_size	ft_format(t_arg *arg, va_list *args)
{
	if (arg->type == 'c')
		return (ft_format_c(arg, args));
	else if (arg->type == 's')
		return (ft_format_s(arg, args));
	else if (arg->type == 'p')
		return (ft_format_p(arg, args));
	else if (arg->type == 'd' || arg->type == 'i')
		return (ft_format_decimal(arg, args));
	else if (arg->type == 'u')
		return (ft_format_unsigned(arg, args));
	else if (arg->type == 'x' || arg->type == 'X')
		return (ft_format_hexadecimal(arg, args));
	else if (arg->type == 'o')
		return (ft_format_octal(arg, args));
	return (ft_print_chr('%'));
}
