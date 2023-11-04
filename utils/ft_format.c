/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:04:56 by luzog             #+#    #+#             */
/*   Updated: 2023/11/04 01:40:56 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_str_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

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

int	ft_format_s(t_arg *arg, va_list *args)
{
	char	*str;
	int		count;
	int		len;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	str = va_arg(*args, char *);
	if (!str)
	{
		if (arg->precision < 0 || arg->precision >= 6)
			str = "(null)";
		else
			str = "";
	}
	if (arg->precision < 0)
		len = ft_str_len(str);
	else
		len = ft_min(ft_str_len(str), arg->precision);
	if (arg->flag_minus)
		count += ft_print_n_str(str, len);
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_n_str(str, len);
	return (count);
}

int	ft_format_p(t_arg *arg, va_list *args)
{
	void	*ptr;
	int		count;
	int		len;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	ptr = va_arg(*args, void *);
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
	{
		len = ft_max(ft_ptrlen(ptr, 0), arg->width) - 2;
		if ((arg->flag_plus || arg->flag_space) && ptr)
		{
			if (arg->flag_plus)
				count += ft_print_chr('+');
			else if (arg->flag_space)
				count += ft_print_chr(' ');
			len--;
		}
		count += ft_print_ptr(ptr, len);
		return (count);
	}
	len = ft_ptrlen(ptr, arg->precision);
	if ((arg->flag_plus || arg->flag_space) && ptr)
		len++;
	if (arg->flag_minus)
	{
		if (arg->flag_plus && ptr)
			count += ft_print_chr('+');
		else if (arg->flag_space && ptr)
			count += ft_print_chr(' ');
		count += ft_print_ptr(ptr, arg->precision);
	}
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
	{
		if (arg->flag_plus && ptr)
			count += ft_print_chr('+');
		else if (arg->flag_space && ptr)
			count += ft_print_chr(' ');
		count += ft_print_ptr(ptr, arg->precision);
	}
	return (count);
}

int	ft_format_d(t_arg *arg, va_list *args)
{
	int		nbr;
	int		count;
	int		len;
	char	spacing;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	nbr = va_arg(*args, int);
	spacing = '\0';
	if (arg->flag_plus)
		spacing = '+';
	else if (arg->flag_space)
		spacing = ' ';
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
	{
		len = ft_max(ft_nbrlen(nbr, spacing), arg->width);
		if (nbr < 0 || spacing)
			len--;
		count += ft_print_nbr(nbr, spacing, len);
		return (count);
	}
	len = ft_nbrnlen(nbr, spacing, arg->precision);
	if (arg->flag_minus)
		count += ft_print_nbr(nbr, spacing, arg->precision);
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_nbr(nbr, spacing, arg->precision);
	return (count);
}

int	ft_format_u(t_arg *arg, va_list *args)
{
	unsigned int	nbr;
	int				count;
	int				len;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	nbr = va_arg(*args, unsigned int);
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
	{
		len = ft_max(ft_unbrlen(nbr), arg->width);
		count += ft_print_unbr(nbr, len);
		return (count);
	}
	len = ft_unbrnlen(nbr, arg->precision);
	if (arg->flag_minus)
		count += ft_print_unbr(nbr, arg->precision);
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_unbr(nbr, arg->precision);
	return (count);
}

int	ft_format_x(t_arg *arg, va_list *args)
{
	unsigned int	nbr;
	int				count;
	int				len;
	int				is_upper;

	count = 0;
	if (arg->width == -2)
		arg->width = va_arg(*args, int);
	if (arg->precision == -2)
		arg->precision = va_arg(*args, int);
	nbr = va_arg(*args, unsigned int);
	is_upper = 0;
	if (arg->type == 'X')
		is_upper = 1;
	if (arg->precision < 0 && arg->flag_zero && !arg->flag_minus)
	{
		len = ft_max(ft_hexlen(nbr), arg->width);
		count += ft_print_hex(nbr, arg->flag_hash, len, is_upper);
		return (count);
	}
	len = ft_hexnlen(nbr, arg->flag_hash, arg->precision);
	if (arg->flag_minus)
		count += ft_print_hex(nbr, arg->flag_hash, arg->precision, is_upper);
	while (arg->width > len)
	{
		count += ft_print_chr(' ');
		arg->width--;
	}
	if (!arg->flag_minus)
		count += ft_print_hex(nbr, arg->flag_hash, arg->precision, is_upper);
	return (count);
}

int	ft_format(t_arg *arg, va_list *args)
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