/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:21:32 by luzog             #+#    #+#             */
/*   Updated: 2023/10/31 16:31:10 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t len)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_cpy = (unsigned char *) dest;
	src_cpy = (unsigned char *) src;
	while (len)
	{
		*dest_cpy = *src_cpy;
		dest_cpy++;
		src_cpy++;
		len--;
	}
	return (dest);
}
