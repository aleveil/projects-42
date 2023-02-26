/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:42:30 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 10:42:31 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t				i;
	unsigned char		*stock;

	stock = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		stock[i] = (unsigned char)c;
		i++;
	}
	return (stock);
}
