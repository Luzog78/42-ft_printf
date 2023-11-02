/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:47:01 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/01 17:28:47 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mem;
	t_ull	sz;

	if (nitems == 0 || size == 0)
		return (malloc(1));
	if ((long long) nitems < 0 || (long long) size < 0)
		return (NULL);
	sz = nitems * size;
	if (sz > MAX_UNSIGNED_LONG)
		return (NULL);
	mem = malloc(sz);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, (size_t) sz);
	return (mem);
}
