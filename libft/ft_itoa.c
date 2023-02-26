/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:20:54 by aleveil           #+#    #+#             */
/*   Updated: 2021/11/23 10:18:22 by aleveil          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tab_len(int n)
{
	size_t	tab_len;

	tab_len = 0;
	if (n < 0)
	{
		n *= -1;
		tab_len++;
	}
	while (n >= 10)
	{
		n /= 10;
		tab_len++;
	}
	tab_len++;
	return (tab_len + 1);
}

char	*ft_itoa(int n)
{
	char	*tab;
	size_t	tab_len;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tab_len = ft_tab_len(n);
	tab = malloc(sizeof(char) * (tab_len));
	if (!tab)
		return (0);
	i = tab_len - 2;
	if (n < 0)
	{
		n *= -1;
		tab[0] = '-';
	}
	while (n >= 10)
	{
		tab[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	tab[i] = n + '0';
	tab[tab_len - 1] = '\0';
	return (tab);
}
