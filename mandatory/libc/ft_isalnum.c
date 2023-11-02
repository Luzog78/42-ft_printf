/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:42:16 by luzog             #+#    #+#             */
/*   Updated: 2023/10/30 13:43:01 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c < '0' || c > '9')
		&& (c < 'A' || c > 'Z')
		&& (c < 'a' || c > 'z'))
		return (0);
	return (1);
}
