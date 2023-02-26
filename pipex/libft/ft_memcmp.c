/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:05:46 by aleveil           #+#    #+#             */
/*   Updated: 2021/11/23 10:45:28 by aleveil          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1char;
	const unsigned char	*s2char;

	i = 0;
	s1char = (const unsigned char *) s1;
	s2char = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while (s1char[i] == s2char[i] && i < n - 1)
		i++;
	return (s1char[i] - s2char[i]);
}
