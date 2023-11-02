/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:25:34 by luzog             #+#    #+#             */
/*   Updated: 2023/10/31 12:49:49 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t len)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *) dest;
	src_cpy = (unsigned char *) src;
	while (len)
	{
		*dest_cpy = *src_cpy;
		dest_cpy++;
		if (*src_cpy == (unsigned char) c)
			return ((void *) dest_cpy);
		src_cpy++;
		len--;
	}
	return (NULL);
}
