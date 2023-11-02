/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzog <luzog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:31:04 by luzog             #+#    #+#             */
/*   Updated: 2023/09/30 17:14:50 by luzog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char const *src)
{
	int		i;
	char	*duplicated;

	i = 0;
	while (src[i])
		i++;
	duplicated = malloc(sizeof(char) * (i + 1));
	if (duplicated != NULL)
	{
		i = 0;
		while (src[i])
		{
			duplicated[i] = src[i];
			i++;
		}
		duplicated[i] = '\0';
	}
	return (duplicated);
}
