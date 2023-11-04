/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:48:46 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/03 20:24:46 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_simplified_unbr(unsigned long long n)
{
	if (n < 10)
		return (ft_print_chr(n + '0'));
	return (ft_print_simplified_nbr(n / 10) + ft_print_chr((n % 10) + '0'));
}

int	ft_print_unbr(unsigned long long n, int len)
{
	int	count;

	count = ft_unbrlen(n);
	while (count < len)
		count += ft_print_chr('0');
	ft_print_simplified_unbr(n);
	return (count);
}

int	ft_unbrlen(unsigned long long n)
{
	if (n < 10)
		return (1);
	return (ft_unbrlen(n / 10) + 1);
}

int	ft_unbrnlen(unsigned long long n, int len)
{
	return (ft_max(ft_unbrlen(n), len));
}
