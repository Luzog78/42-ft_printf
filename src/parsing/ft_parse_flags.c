/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:09:30 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 04:15:58 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_parse_flags(t_arg *arg, const char *str)
{
	t_signed_size	i;

	i = 0;
	while (ft_str_contains("-+ 0#", str[i]))
	{
		if (str[i] == '-')
			arg->flag_minus = 1;
		else if (str[i] == '+')
			arg->flag_plus = 1;
		else if (str[i] == ' ')
			arg->flag_space = 1;
		else if (str[i] == '0')
			arg->flag_zero = 1;
		else if (str[i] == '#')
			arg->flag_hash = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}
