/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:03:54 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 04:26:27 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*ft_parse(const char *str)
{
	t_arg			*arg;
	t_signed_size	i;

	i = 0;
	arg = malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	ft_init_flags(arg);
	if (str[i] && !ft_str_contains("cspdiuxX%", str[i]))
		i += ft_parse_flags(arg, str);
	if (str[i] && !ft_str_contains("cspdiuxX%", str[i]))
		i += ft_parse_width(arg, str + i);
	if (str[i] && !ft_str_contains("cspdiuxX%", str[i]))
		i += ft_parse_precision(arg, str + i);
	if (str[i] && !ft_str_contains("cspdiuxX%", str[i]))
		i += ft_parse_length(arg, str + i);
	if (ft_str_contains("cspdiuxX%", str[i]))
	{
		arg->type = str[i];
		arg->length = i + 1;
	}
	return (arg);
}
