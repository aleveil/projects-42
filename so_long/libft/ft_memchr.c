/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:50:23 by aleveil           #+#    #+#             */
/*   Updated: 2021/12/01 17:14:27 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*schar;
	unsigned char	cchar;

	i = 0;
	if (!c && !n)
		return (0);
	schar = (unsigned char *) s;
	cchar = (unsigned char) c;
	while (schar[i] != cchar)
	{
		i++;
		if (i >= n)
			return (0);
	}
	return ((void *) schar + i);
}
