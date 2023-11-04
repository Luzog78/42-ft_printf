/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:18:07 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 01:27:28 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_simplified_nbr(long long n)
{
	if (n == -9223372036854775807LL - 1LL)
		return (ft_print_str("9223372036854775808"));
	if (n < 0)
		return (ft_print_simplified_nbr(-n));
	if (n < 10)
		return (ft_print_chr(n + '0'));
	return (ft_print_simplified_nbr(n / 10) + ft_print_chr((n % 10) + '0'));
}

int	ft_print_nbr(long long n, char spacing, int len)
{
	int	count_spc;
	int	count_num;

	count_spc = 0;
	count_num = ft_nbrlen(n, '\0');
	if (n < 0)
	{
		count_spc += ft_print_chr('-');
		count_num--;
	}
	else if (spacing)
	{
		count_spc += ft_print_chr(spacing);
	}
	while (count_num < len)
		count_num += ft_print_chr('0');
	ft_print_simplified_nbr(n);
	return (count_spc + count_num);
}

int	ft_nbrlen(long long n, char spacing)
{
	if (n == -9223372036854775807LL - 1LL)
		return (20);
	if (n < 0 || spacing)
		return (ft_nbrlen(-n, '\0') + 1);
	if (n < 10)
		return (1);
	return (ft_nbrlen(n / 10, '\0') + 1);
}

int	ft_nbrnlen(long long n, char spacing, int len)
{
	if (n < 0 || spacing)
		return (ft_max(ft_nbrlen(n, spacing), len + 1));
	return (ft_max(ft_nbrlen(n, spacing), len));
}
