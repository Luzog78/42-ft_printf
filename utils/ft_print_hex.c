/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:33:29 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 01:33:29 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_simplified_hex(unsigned long long n, int is_upper)
{
	if (n < 16)
	{
		ft_print_chr(ft_ctox(n, is_upper));
		return ;
	}
	ft_print_simplified_hex(n / 16, is_upper);
	ft_print_chr(ft_ctox(n % 16, is_upper));
}

int	ft_print_hex(unsigned long long n, int is_prefixed, int len, int is_upper)
{
	int	count_pfx;
	int	count_hex;

	count_pfx = 0;
	count_hex = ft_hexlen(n);
	if (is_prefixed && n != 0)
	{
		if (is_upper)
			count_pfx += ft_print_str("0X");
		else
			count_pfx += ft_print_str("0x");
	}
	while (count_hex < len)
		count_hex += ft_print_chr('0');
	ft_print_simplified_hex(n, is_upper);
	return (count_pfx + count_hex);
}

int	ft_hexnlen(unsigned long long n, int is_prefixed, int len)
{
	if (is_prefixed && n != 0)
		return (ft_max(ft_hexlen(n), len) + 2);
	return (ft_max(ft_hexlen(n), len));
}

int	ft_hexlen(unsigned long long n)
{
	if (n < 16)
		return (1);
	return (ft_hexlen(n / 16) + 1);
}
