/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:08:42 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 04:16:30 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_parse_width(t_arg *arg, const char *str)
{
	t_signed_size	i;

	i = 0;
	if (str[i] == '*')
	{
		arg->width = -2;
		i++;
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		arg->width = ft_uatoi(str);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (i);
}
