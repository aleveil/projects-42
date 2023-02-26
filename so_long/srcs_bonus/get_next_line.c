/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:42:58 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/08 18:00:17 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strichr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

static char	*ft_join(char *s1, char *s2)
{
	char	*result;
	int		result_len;
	int		i;
	int		j;

	result_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

static void	ft_get_line(char **s_buf, char **line)
{
	char	*tmp_adress;
	int		index;

	tmp_adress = *s_buf;
	index = ft_strichr(*s_buf, '\n');
	if (index > -1)
	{
		*line = ft_strndup(*s_buf, index + 1);
		*s_buf = ft_strndup(*s_buf + index + 1, ft_strlen(*s_buf) - index);
	}
	else
	{
		*line = ft_strndup(*s_buf, ft_strlen(*s_buf));
		*s_buf = NULL;
	}
	free(tmp_adress);
}

static int	ft_read(int fd, char **s_buf, char **buf, char **line)
{
	char	*tmp_adress;
	int		ret;

	ret = 1;
	while (ft_strichr(*s_buf, '\n') < 0 && ret)
	{
		ret = read(fd, *buf, BUFFER_SIZE);
		(*buf)[ret] = '\0';
		tmp_adress = *s_buf;
		*s_buf = ft_join(*s_buf, *buf);
		free(tmp_adress);
	}
	free(*buf);
	ft_get_line(s_buf, line);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*s_buf = NULL;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (NULL);
	}
	if (!s_buf)
		s_buf = ft_strndup("", 0);
	if (ft_read(fd, &s_buf, &buf, &line) == 0 && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
