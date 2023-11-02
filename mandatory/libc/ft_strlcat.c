/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:31:53 by luzog             #+#    #+#             */
/*   Updated: 2023/11/01 14:22:54 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	full_size;
	size_t	counter;
	size_t	i;

	if (size == 0 && dest == NULL)
		return (0);
	i = 0;
	while (dest[i] && i < size)
		i++;
	full_size = ft_strlen(src) + i;
	if (size > 0)
	{
		counter = ft_strlen(dest);
		i = 0;
		while (counter < size - 1 && src[i] != '\0')
		{
			dest[counter] = src[i];
			counter++;
			i++;
		}
		dest[counter] = '\0';
	}
	return (full_size);
}
