/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:33:29 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 06:40:37 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_print_oct(unsigned long long n,
	int is_prefixed, t_signed_size len)
{
	t_signed_size	count_pfx;
	t_signed_size	count_oct;

	if (n == 0 && len == 0)
		return (0);
	count_pfx = 0;
	count_oct = ft_octlen(n);
	if (is_prefixed && n != 0)
		count_pfx += ft_print_str("0");
	while (count_oct < len)
		count_oct += ft_print_chr('0');
	ft_print_simplified_oct(n);
	return (count_pfx + count_oct);
}
