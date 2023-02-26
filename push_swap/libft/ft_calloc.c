/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:40:28 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 10:40:30 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (nmemb == 0)
		return (malloc(0));
	if (size == 0)
		return (malloc(0));
	tmp = malloc(nmemb * size);
	if (tmp == NULL)
		return (NULL);
	ft_memset((unsigned char *)tmp, 0, nmemb * size);
	return (tmp);
}
