/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:04:24 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:53:05 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_nbrlen(long long n, char spacing)
{
	if (n == -9223372036854775807LL - 1LL)
		return (20);
	if (n < 0 || spacing)
		return (ft_nbrlen(-n, '\0') + 1);
	if (n < 10)
		return (1);
	return (ft_nbrlen(n / 10, '\0') + 1);
}
