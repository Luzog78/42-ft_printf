/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:04:12 by luzog             #+#    #+#             */
/*   Updated: 2023/10/31 13:16:09 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*mem;

	mem = (unsigned char *) dest;
	while (len)
	{
		*mem = (unsigned char) c;
		mem++;
		len--;
	}
	return (dest);
}
