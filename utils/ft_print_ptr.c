/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:49:30 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/02 09:47:42 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	if (!ptr)
		return (ft_print_str("(nil)"));
	return (ft_print_str("0x") + ft_print_hex((unsigned long) ptr, 0));
}
