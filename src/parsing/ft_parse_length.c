/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:07:53 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 03:27:28 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_parse_length(t_arg *arg, const char *str)
{
	t_signed_size	i;

	i = 0;
	if (ft_str_contains("hl", str[i]))
	{
		if (str[i] == 'h')
			arg->size = 2;
		else if (str[i] == 'l')
			arg->size = 3;
		i++;
	}
	if (ft_str_contains("hl", str[i]))
	{
		if (str[i] == 'h')
			arg->size = 1;
		else if (str[i] == 'l')
			arg->size = 4;
		i++;
	}
	return (i);
}
