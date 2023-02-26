/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:45:22 by aleveil           #+#    #+#             */
/*   Updated: 2021/11/12 13:43:05 by aleveil          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*bchar;

	i = 0;
	bchar = (char *) b;
	while (i < len)
	{
		bchar[i] = (char) c;
		i++;
	}
	return ((void *)bchar);
}
