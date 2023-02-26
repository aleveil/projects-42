/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:30:02 by aleveil           #+#    #+#             */
/*   Updated: 2021/11/23 10:44:43 by aleveil          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;
	size_t			i;

	result = malloc(nmemb * size);
	if (!result)
		return (0);
	i = 0;
	while (i < nmemb * size)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
