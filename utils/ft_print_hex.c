/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:33:29 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/02 09:33:18 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long n, int is_upper)
{
	if (n < 16)
		return (ft_print_chr(ft_ctox(n, is_upper)));
	return (ft_print_hex(n / 16, is_upper)
		+ ft_print_chr(ft_ctox(n % 16, is_upper)));
}