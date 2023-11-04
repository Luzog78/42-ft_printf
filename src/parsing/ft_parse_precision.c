/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:08:19 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:45:56 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_parse_precision(t_arg *arg, const char *str)
{
	t_signed_size	i;

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
			arg->precision = ft_uatoi(str + i);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
	}
	return (i);
}
