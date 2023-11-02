/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzog <luzog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:53:28 by luzog             #+#    #+#             */
/*   Updated: 2023/10/04 01:53:41 by luzog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (char) c)
			last = (char *) str;
		str++;
	}
	if (*str == (char) c)
		return ((char *) str);
	return (last);
}
