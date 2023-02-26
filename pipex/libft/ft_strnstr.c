/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:46:05 by aleveil           #+#    #+#             */
/*   Updated: 2021/12/01 17:30:23 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlelen;

	if (needle[0] == '\0')
		return ((char *)haystack);
	needlelen = ft_strlen(needle);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (!ft_strncmp(&haystack[i], needle, needlelen)
			&& needlelen + i <= len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
