/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_simplified_unbr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:06:55 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:48:08 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_print_simplified_unbr(unsigned long long n)
{
	if (n < 10)
		return (ft_print_chr(n + '0'));
	return (ft_print_simplified_nbr(n / 10) + ft_print_chr((n % 10) + '0'));
}
