/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:33:12 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/02 09:33:24 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_ctox(unsigned long long c, int is_upper)
{
	if (c < 10)
		return ('0' + c);
	if (is_upper)
		return ('A' + c - 10);
	return ('a' + c - 10);
}
