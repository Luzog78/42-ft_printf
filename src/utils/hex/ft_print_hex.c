/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:33:29 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/07 01:51:09 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_print_hex(unsigned long long n,
	int is_prefixed, t_signed_size len, char type)
{
	t_signed_size	count_pfx;
	t_signed_size	count_hex;

	if (n == 0 && len == 0)
		return (0);
	count_pfx = 0;
	count_hex = ft_hexlen(n, 0);
	if (is_prefixed && n != 0)
	{
		if (type == 'X')
			count_pfx += ft_print_str("0X");
		else
			count_pfx += ft_print_str("0x");
	}
	while (count_hex < len)
		count_hex += ft_print_chr('0');
	ft_print_simplified_hex(n, type == 'X');
	return (count_pfx + count_hex);
}
