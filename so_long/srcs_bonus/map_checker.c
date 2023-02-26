/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:28:37 by marvin            #+#    #+#             */
/*   Updated: 2023/01/06 15:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_char_check(char	**map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (!is_char_valid(map[x][y]))
				return (FALSE);
			y++;
		}
		y = 0;
		x++;
	}
	return (TRUE);
}

int	is_rect_check(char	**map)
{
	int	i;
	int	firstlen;

	i = 1;
	firstlen = ft_strlen(map[0]);
	while (map[i])
	{
		if (firstlen != (int)ft_strlen(map[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_close_check(t_map_data map_data)
{
	if (is_lines_closed(map_data) && is_cols_closed(map_data))
		return (TRUE);
	else
		return (FALSE);
}

int	is_count_check(t_data *data)
{
	int	nb_exit;
	int	nb_start;
	int	nb_items;

	nb_exit = char_counter(data->map_data.map, MAP_EXIT);
	nb_start = char_counter(data->map_data.map, MAP_START);
	nb_items = char_counter(data->map_data.map, MAP_ITEM);
	data->map_data.nb_items = nb_items;
	if (nb_exit != 1 || nb_start != 1 || nb_items < 1)
		return (FALSE);
	else
		return (TRUE);
}

void	check_map(t_data *data)
{
	if (!is_char_check(data->map_data.map))
	{
		free_matrix(data->map_data.map);
		error_free("Invalid map (invalid char)", data);
	}
	if (!is_rect_check(data->map_data.map))
	{
		free_matrix(data->map_data.map);
		error_free("Invalid map (non-rectangular map)", data);
	}
	if (!is_close_check(data->map_data))
	{
		free_matrix(data->map_data.map);
		error_free("Invalid map (unclosed map)", data);
	}
	if (!is_count_check(data))
	{
		free_matrix(data->map_data.map);
		error_free("Invalid map (exit, start or item missing)", data);
	}
}
