/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:02:12 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:46:28 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_hexnlen(unsigned long long n,
	int is_prefixed, t_signed_size len)
{
	if (is_prefixed && n != 0)
		return (ft_max(ft_hexlen(n), len) + 2);
	return (ft_max(ft_hexlen(n), len));
}
