/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:42:59 by ysabik            #+#    #+#             */
/*   Updated: 2023/10/30 21:43:05 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = list;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
