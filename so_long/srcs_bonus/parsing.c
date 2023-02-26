/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:36:20 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 11:36:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_map_max(t_data *data)
{
	int		i;

	data->map_data.y_max = ft_strlen(data->map_data.map[0]);
	i = 0;
	while (data->map_data.map[i] != NULL)
		i++;
	data->map_data.x_max = i;
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (FALSE);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (FALSE);
		i++;
	}
	if (str[i - 1] == '\n')
		return (FALSE);
	return (TRUE);
}

char	**get_map(int fd, t_data *data)
{
	char	*line;
	char	*all_lines;
	char	**result;

	all_lines = ft_strdup("");
	line = get_next_line(fd);
	if (line == NULL)
	{
		close_free(fd, all_lines);
		error_free("Invalid map (map empty)", data);
	}
	while (line != NULL)
	{
		all_lines = ft_strjoin_free(all_lines, line);
		line = get_next_line(fd);
	}
	if (!check_newline(all_lines))
	{
		close_free(fd, all_lines);
		error_free("Invalid map (consecutives newline(s))", data);
	}
	result = ft_split(all_lines, '\n');
	free(all_lines);
	return (result);
}

void	parse_map(char *filename, t_data *data)
{
	int	fd;

	if (!is_check_ber(filename))
		error_free("Invalid file (must be a .ber file)", data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_free("Invalid file descriptor", data);
	data->map_data.map = get_map(fd, data);
	close(fd);
	set_map_max(data);
}
