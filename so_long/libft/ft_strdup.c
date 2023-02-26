/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:38:44 by aleveil           #+#    #+#             */
/*   Updated: 2021/11/19 16:52:01 by aleveil          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		slen;

	slen = ft_strlen(s);
	result = ft_calloc(slen + 1, sizeof(char));
	if (!result)
		return (0);
	ft_memcpy(result, s, slen + 1);
	return (result);
}
