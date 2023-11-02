/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:03:54 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/02 18:30:43 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_arg *arg)
{
	arg->flag_minus = 0;
	arg->flag_plus = 0;
	arg->flag_space = 0;
	arg->flag_zero = 0;
	arg->flag_hash = 0;
	arg->width = -1;
	arg->precision = -1;
	arg->length = 0;
	arg->type = '\0';
}

int	ft_str_contains(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr);
}

size_t	ft_parse_flags(t_arg *arg, const char *str)
{
	size_t	i;

	i = 0;
	while (ft_str_contains("-+ 0#", str[i]))
	{
		if (str[i] == '-' && arg->flag_minus == 0)
			arg->flag_minus = 1;
		else if (str[i] == '-' && arg->flag_plus == 1)
			arg->flag_plus = 2;
		else if (str[i] == '+' && arg->flag_plus == 0)
			arg->flag_plus = 1;
		else if (str[i] == ' ' && arg->flag_space == 0)
			arg->flag_space = 1;
		else if (str[i] == '0' && arg->flag_zero == 0)
			arg->flag_zero = 1;
		else if (str[i] == '#' && arg->flag_hash == 0)
			arg->flag_hash = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}

int	ft_parse_width(t_arg *arg, const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '*')
	{
		arg->width = -2;
		if (arg->flag_minus == 2)
			return (-1);
		i++;
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		arg->width = ft_atoi(str);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i);
}

int	ft_parse_precision(t_arg *arg, const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		i++;
		if (str[i] == '*')
		{
			arg->precision = -2;
			i++;
		}
		else
		{
			arg->precision = ft_atoi(str);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
	}
	return (i);
}

int	ft_parse_lenght(t_arg *arg, const char *str)
{
	int	i;

	i = 0;
	if (ft_str_contains("hl", str[i]))
	{
		if (str[i] == 'h')
			arg->length = 2;
		else if (str[i] == 'l')
			arg->length = 3;
		i++;
	}
	if (ft_str_contains("hl", str[i]))
	{
		if (str[i] == 'h')
			arg->length = 1;
		else if (str[i] == 'l')
			arg->length = 4;
		i++;
	}
	return (i);
}

t_arg	*ft_parse(const char *str)
{
	t_arg	*flags;
	size_t	i;

	i = 0;
	flags = malloc(sizeof(t_arg));
	if (!flags)
		return (NULL);
	ft_init_flags(flags);
	if (str[i] && !ft_str_contains("cspdiuxX%", str[i]))
		i += ft_parse_flags(flags, str);
	if (str[i] && !ft_str_contains("cspdiuxX%", str[i]))
		i += ft_parse_width(flags, str + i);
	if (str[i] && !ft_str_contains("cspdiuxX%", str[i]))
		i += ft_parse_precision(flags, str + i);
	if (str[i] && !ft_str_contains("cspdiuxX%", str[i]))
		i += ft_parse_lenght(flags, str + i);
	if (str[i] && !ft_str_contains("cspdiuxX%", str[i]))
	{
		free(flags);
		return (NULL);
	}
	flags->type = str[i];
	return (flags);
}
