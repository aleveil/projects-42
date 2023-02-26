/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:05:38 by aleveil           #+#    #+#             */
/*   Updated: 2021/11/25 18:28:36 by aleveil          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_spaces_check(const char *str, size_t *i)
{
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\r'
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == ' ')
		(*i)++;
}

static int	ft_sign_check(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned int	result;

	i = 0;
	result = 0;
	ft_spaces_check(str, &i);
	sign = ft_sign_check(str, &i);
	while (ft_isdigit(str[i]))
	{
		result = result + str[i] - 48;
		i++;
		if (ft_isdigit(str[i]))
		{
			if (result * 10 > 2147483647 && sign > 0)
				return (-1);
			else if (result * 10 > 2147483648 && sign < 0)
				return (0);
			else
				result *= 10;
		}
	}
	return (result * sign);
}
