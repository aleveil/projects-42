/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:42:58 by aleveil           #+#    #+#             */
/*   Updated: 2022/03/03 02:21:13 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_get_line(char **s_buf, char **line)
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

int	ft_read(int fd, char **s_buf, char **buf, char **line)
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
