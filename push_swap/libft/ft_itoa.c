/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:42:02 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 10:42:06 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_allocm(unsigned int len, int n)
{
	char	*dest;

	if (n < 0)
		dest = (char *)malloc(sizeof(char) * len + 1 + 1);
	else
		dest = (char *)malloc(sizeof(char) * len + 1);
	return (dest);
}

static unsigned int	ft_checksign(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	return (nb);
}

static char	*ft_finalizer(char *src, unsigned int index,
				unsigned int len, unsigned int nb)
{
	src[index] = nb % 10 + 48;
	src[len] = '\0';
	return (src);
}

char	*ft_itoa(int n)
{
	char			*dest;
	unsigned int	len;
	unsigned int	nb;
	unsigned int	i;

	nb = ft_checksign(n);
	len = ft_nblen(nb);
	dest = ft_allocm(len, n);
	i = 0;
	if (!dest)
		return (NULL);
	if (n < 0)
	{
		dest[i] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		dest[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	ft_finalizer(dest, i, len, nb);
	return (dest);
}
