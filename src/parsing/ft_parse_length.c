/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:07:53 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/06 22:08:48 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_parse_length(t_arg *arg, const char *str)
{
	if (str[0] == 'h')
	{
		if (str[1] == 'h')
		{
			arg->size = 1;
			return (2);
		}
		arg->size = 2;
		return (1);
	}
	else if (str[0] == 'l')
	{
		if (str[1] == 'l')
		{
			arg->size = 4;
			return (2);
		}
		arg->size = 3;
		return (1);
	}
	return (0);
}
