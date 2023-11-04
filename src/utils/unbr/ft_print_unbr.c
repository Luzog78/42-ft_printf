/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:48:46 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:48:19 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_print_unbr(unsigned long long n, t_signed_size len)
{
	t_signed_size	count;

	count = ft_unbrlen(n);
	while (count < len)
		count += ft_print_chr('0');
	ft_print_simplified_unbr(n);
	return (count);
}
