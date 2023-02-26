/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:37:33 by aleveil           #+#    #+#             */
/*   Updated: 2021/11/23 10:43:46 by aleveil          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup_word(const char *s, char c, size_t *s_index)
{
	char	*tab;
	size_t	i;
	size_t	size;

	i = 0;
	while (s[*s_index] == c)
		*s_index += 1;
	size = *s_index;
	while (s[size] != c && s[size] != '\0')
		size++;
	size -= *s_index;
	tab = malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (0);
	while (s[*s_index] != c && s[*s_index] != '\0')
	{
		tab[i] = s[*s_index];
		*s_index += 1;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static size_t	ft_tab_len(char const *s, char c)
{
	int	i;
	int	tab_len;

	i = 0;
	tab_len = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			tab_len++;
		i++;
	}
	if (s[0] != c && s[0] != '\0')
		tab_len++;
	return (tab_len + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	tab_len;
	size_t	i;
	size_t	s_index;

	i = 0;
	s_index = 0;
	if (!s)
		return (0);
	tab_len = ft_tab_len(s, c);
	tab = malloc(sizeof(char *) * tab_len);
	if (!tab)
		return (0);
	while (i < tab_len - 1)
	{
		tab[i] = ft_strdup_word(s, c, &s_index);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
