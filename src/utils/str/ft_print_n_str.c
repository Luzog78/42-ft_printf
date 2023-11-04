/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:05:46 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:47:55 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_print_n_str(char const *str, t_signed_size n)
{
	t_signed_size	i;

	i = 0;
	while (str[i] && i < n)
		i++;
	write(1, str, i);
	return (i);
}
