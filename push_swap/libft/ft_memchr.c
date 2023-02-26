/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:42:12 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 10:42:14 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	j;

	i = 0;
	j = (unsigned char) c;
	s2 = (unsigned char *)s;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (s2[i] == j)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
