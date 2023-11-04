/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_simplified_hex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:02:31 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:02:42 by ysabik           ###   ########.fr       */
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
