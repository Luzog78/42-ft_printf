/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:01:54 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/07 00:36:19 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_hexlen(unsigned long long n, int is_prefixed)
{
	if (is_prefixed && n != 0)
		return (ft_hexlen(n, 0) + 2);
	if (n < 16)
		return (1);
	return (ft_hexlen(n / 16, 0) + 1);
}
