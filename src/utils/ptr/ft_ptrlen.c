/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:05:17 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:47:42 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_ptrlen(void *ptr, t_signed_size len)
{
	if (!ptr)
		return (5);
	return (ft_hexnlen((unsigned long) ptr, 1, len));
}
