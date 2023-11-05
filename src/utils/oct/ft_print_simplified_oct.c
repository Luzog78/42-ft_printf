/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_simplified_oct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:02:31 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/05 06:43:11 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_simplified_oct(unsigned long long n)
{
	if (n < 8)
	{
		ft_print_chr('0' + n);
		return ;
	}
	ft_print_simplified_oct(n / 8);
	ft_print_chr('0' + (n % 8));
}
