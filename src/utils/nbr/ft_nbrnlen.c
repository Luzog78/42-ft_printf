/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:04:38 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:47:18 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_nbrnlen(long long n, char spacing, t_signed_size len)
{
	if (n < 0 || spacing)
		return (ft_max(ft_nbrlen(n, spacing), len + 1));
	return (ft_max(ft_nbrlen(n, spacing), len));
}
