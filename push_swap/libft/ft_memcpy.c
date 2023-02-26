/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:42:22 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 10:42:24 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict_dst, const void *restrict_src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char *) restrict_dst;
	src = (unsigned char *) restrict_src;
	if (n == 0)
		return (restrict_dst);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (restrict_dst);
}
