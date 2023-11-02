/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:43:18 by luzog             #+#    #+#             */
/*   Updated: 2023/10/30 20:01:15 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_whitespace(char c);

int	ft_atoi(char const *str)
{
	int		sum;
	int		negative_multiplier;

	while (ft_is_whitespace(*str))
		str++;
	negative_multiplier = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative_multiplier *= -1;
		str++;
	}
	sum = 0;
	while ('0' <= *str && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	return (sum * negative_multiplier);
}

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
