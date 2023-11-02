/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:00:13 by luzog             #+#    #+#             */
/*   Updated: 2023/10/31 13:08:42 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*mem_cpy;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	mem_cpy = (char *) mem;
	while (size)
	{
		*mem_cpy = 0;
		mem_cpy++;
		size--;
	}
	return (mem);
}
