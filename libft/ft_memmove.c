/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:06:14 by aleveil           #+#    #+#             */
/*   Updated: 2021/11/25 17:09:19 by aleveil          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstchar;
	unsigned char	*srcchar;
	size_t			i;

	dstchar = (unsigned char *) dst;
	srcchar = (unsigned char *) src;
	i = len;
	if (src < dst)
	{
		while (i > 0)
		{
			i--;
			dstchar[i] = srcchar[i];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return ((void *)dstchar);
}
