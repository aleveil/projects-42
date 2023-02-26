/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:46:04 by marvin            #+#    #+#             */
/*   Updated: 2023/01/10 09:00:18 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_char_valid(char c)
{
	if (c == MAP_SPACE
		|| c == MAP_WALL
		|| c == MAP_ITEM
		|| c == MAP_EXIT
		|| c == MAP_START)
		return (1);
	else
		return (0);
}

int	is_lines_closed(t_map_data map_data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map_data.map[0][y])
	{
		if (map_data.map[0][y] != MAP_WALL)
			return (FALSE);
		y++;
	}
	x = map_data.x_max - 1;
	y = 0;
	while (y < map_data.y_max)
	{
		if (map_data.map[x][y] != MAP_WALL)
			return (FALSE);
		y++;
	}
	return (TRUE);
}

int	is_cols_closed(t_map_data map_data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < map_data.x_max)
	{
		if (map_data.map[x][0] != MAP_WALL)
			return (FALSE);
		x++;
	}
	y = map_data.y_max - 1;
	x = 0;
	while (x < map_data.x_max)
	{
		if (map_data.map[x][y] != MAP_WALL)
			return (FALSE);
		x++;
	}
	return (TRUE);
}

int	char_counter(char **matrix, char c)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (matrix[x])
	{
		while (matrix[x][y])
		{
			if (matrix[x][y] == c)
				i++;
			y++;
		}
		y = 0;
		x++;
	}
	return (i);
}
