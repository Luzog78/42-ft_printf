/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:10:48 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:10:53 by ysabik           ###   ########.fr       */
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
	arg->size = 0;
	arg->type = '\0';
	arg->length = 0;
}
