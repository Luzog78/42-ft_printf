/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:43:49 by luzog             #+#    #+#             */
/*   Updated: 2023/10/30 18:42:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_len(char const *str, char c);
static void	ft_split_fill(char const *str, char c, char **splitted);
static void	ft_count(int *counter, int *str_j, char const *str, char c);

char	**ft_split(char const *str, char c)
{
	int		len;
	char	**splitted;

	len = ft_split_len(str, c);
	splitted = malloc(sizeof(char *) * (len + 1));
	if (splitted == NULL)
		return (NULL);
	ft_split_fill(str, c, splitted);
	splitted[len] = 0;
	return (splitted);
}

static int	ft_split_len(char const *str, char c)
{
	int	i;
	int	j;
	int	tab_len;
	int	counter;

	tab_len = 0;
	i = -1;
	while (i == -1 || str[i])
	{
		if (i == -1 || str[i] == c)
		{
			counter = 0;
			j = i + 1;
			while (str[j] && str[j] != c)
			{
				counter++;
				j++;
				i++;
			}
			if (counter)
				tab_len += 1;
		}
		i++;
	}
	return (tab_len);
}

static void	ft_split_fill(char const *str, char c, char **splitted)
{
	int	str_i;
	int	str_j;
	int	tab_index;
	int	counter;

	tab_index = 0;
	str_i = -2;
	while (++str_i == -1 || str[str_i])
	{
		if (str_i == -1 || str[str_i] == c)
		{
			str_j = str_i + 1;
			ft_count(&counter, &str_j, str, c);
			if (counter)
			{
				splitted[tab_index] = malloc(sizeof(char) * (counter + 1));
				str_j = -1;
				while (++str_j < counter)
					splitted[tab_index][str_j] = str[str_i + 1 + str_j];
				splitted[tab_index][str_j] = '\0';
				tab_index++;
			}
			str_i += counter;
		}
	}
}

static void	ft_count(int *counter, int *str_j, char const *str, char c)
{
	*counter = 0;
	while (str[*str_j] && str[*str_j] != c)
	{
		*counter += 1;
		*str_j += 1;
	}
}
