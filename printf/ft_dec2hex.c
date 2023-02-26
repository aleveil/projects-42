/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec2hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:49:41 by aleveil           #+#    #+#             */
/*   Updated: 2021/11/29 17:05:29 by aleveil          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_hexlen(unsigned int unb)
{
	int	i;

	i = 0;
	while (unb >= 16)
	{
		unb /= 16;
		i++;
	}
	return (i + 2);
}

char	*ft_dec2hex(int nb)
{
	unsigned int	unb;
	char		*base;
	int		hexnb_len;
	char		*hexnb;
	int		i;

	unb = nb < 0 ? -nb : nb;
	base = "0123456789abcdef";
	hexnb_len = ft_hexlen(unb);
	hexnb = malloc(sizeof(char) * (hexnb_len + (nb < 0  ? 1 : 0)));
	if (!hexnb)
		return (0);
	i = hexnb_len;
	hexnb[--i] = '\0';
	while (nb >= 16)
	{
		hexnb[--i] = base[nb % 16];
		nb /= 16;
	}
	hexnb[i] = base[nb % 16];
	if (nb < 0)
		hexnb[0] = '-';
	return (hexnb);
}

#include <stdio.h>
int	main()
{
	printf("%s\n", ft_dec2hex(255));
}
