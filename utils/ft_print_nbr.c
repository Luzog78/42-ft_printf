/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:18:07 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/02 09:48:14 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(long long n)
{
	if (n == -9223372036854775807LL - 1LL)
		return (ft_print_str("-9223372036854775808"));
	if (n < 0)
		return (ft_print_chr('-') + ft_print_nbr(-n));
	if (n < 10)
		return (ft_print_chr(n + '0'));
	return (ft_print_nbr(n / 10) + ft_print_chr((n % 10) + '0'));
}
