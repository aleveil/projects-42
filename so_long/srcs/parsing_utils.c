/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:27:04 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/10 16:56:29 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	close_free(int fd, char *all_lines)
{
	close(fd);
	free(all_lines);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, s1, s1_len + 1);
	ft_strlcat(result, s2, s1_len + s2_len + 1);
	free(s1);
	free(s2);
	return (result);
}

int	is_check_ber(char *filename)
{
	char	*filename_end;

	filename_end = filename + (ft_strlen(filename) - 4);
	if (ft_strncmp(filename_end, ".ber", 4))
		return (FALSE);
	else
		return (TRUE);
}
