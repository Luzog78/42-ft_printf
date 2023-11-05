/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:02:12 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 06:40:49 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_octnlen(unsigned long long n,
	int is_prefixed, t_signed_size len)
{
	if (n == 0 && len == 0)
		return (0);
	if (is_prefixed && n != 0)
		return (ft_max(ft_octlen(n), len) + 1);
	return (ft_max(ft_octlen(n), len));
}
