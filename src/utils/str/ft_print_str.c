/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:16:49 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/04 02:48:02 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_signed_size	ft_print_str(char const *str)
{
	t_signed_size	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}
