/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:42:54 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 10:42:56 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len_word(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	word_getsize(char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	total;

	i = 0;
	j = 0;
	total = 0;
	while (s[i])
	{
			j = len_word(s + i, c);
		if (j > 0)
		{
			total++;
			i--;
		}
		i += j;
		i++;
	}
	return (total);
}

static	int	check_n_comp(char *s, char c)
{
	int		i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == c)
			counter++;
		i++;
	}
	if (ft_strlen(s) == counter)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**tab;

	i = 0;
	j = 0;
	check_n_comp(((char *)s), c);
	size = word_getsize((char *)s, c);
	tab = malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (((char *)s)[i])
	{
		size = len_word((char *)s + i, c);
		if (size > 0)
		{
			tab[j++] = ft_substr(s, i, size);
			i--;
		}
		i += size;
		i++;
	}
	tab[j] = 0;
	return (tab);
}
