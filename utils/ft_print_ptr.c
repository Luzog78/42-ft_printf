/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:49:30 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/03 23:43:57 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr, int len)
{
	if (!ptr)
		return (ft_print_str("(nil)"));
	return (ft_print_hex((unsigned long) ptr, 1, len, 0));
}

int	ft_ptrlen(void *ptr, int len)
{
	if (!ptr)
		return (5);
	return (ft_hexnlen((unsigned long) ptr, 1, len));
}
