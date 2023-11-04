/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:49:30 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:47:38 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_print_ptr(void *ptr, t_signed_size len)
{
	if (!ptr)
		return (ft_print_str("(nil)"));
	return (ft_print_hex((unsigned long) ptr, 1, len, 0));
}
