/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:42:26 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 10:42:28 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*tdst;
	const unsigned char	*tsrc;

	tdst = dst;
	tsrc = src;
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{		
			i--;
			tdst[i] = tsrc[i];
		}
	}
	if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
