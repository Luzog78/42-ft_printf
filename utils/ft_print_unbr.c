/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:48:46 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/02 09:49:18 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned long long n)
{
	if (n < 10)
		return (ft_print_chr(n + '0'));
	return (ft_print_nbr(n / 10) + ft_print_chr((n % 10) + '0'));
}
