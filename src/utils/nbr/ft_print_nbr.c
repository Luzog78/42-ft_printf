/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:18:07 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:47:27 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_print_nbr(long long n, char spacing, t_signed_size len)
{
	t_signed_size	count_spc;
	t_signed_size	count_num;

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
