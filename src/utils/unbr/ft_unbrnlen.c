/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:06:19 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 04:20:48 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_unbrnlen(unsigned long long n, t_signed_size len)
{
	if (n == 0 && len == 0)
		return (0);
	return (ft_max(ft_unbrlen(n), len));
}
