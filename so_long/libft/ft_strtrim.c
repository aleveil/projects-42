/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strtrim.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aleveil <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/11/21 17:04:12 by aleveil		   #+#	#+#			 */
/*   Updated: 2021/11/23 14:06:39 by aleveil          ###   ########lyon.fr   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_trim_len(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (ft_is_set(s1[start], set) && s1[start] != '\0')
		start++;
	while (ft_is_set(s1[end - 1], set) && end > start)
		end--;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	trim_len;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (0);
	trim_len = ft_trim_len(s1, set);
	result = malloc(sizeof(char) * (trim_len + 1));
	if (!result)
		return (0);
	if (trim_len > 0)
	{
		while (ft_is_set(s1[i], set))
			i++;
		ft_strlcpy(result, &s1[i], trim_len + 1);
	}
	else
		result[0] = '\0';
	return (result);
}
