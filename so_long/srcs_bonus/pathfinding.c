/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:08:36 by marvin            #+#    #+#             */
/*   Updated: 2023/01/10 15:23:06 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_visited(t_map_data map_data)
{
	char	**visited;
	int		x;
	int		y;

	visited = malloc(sizeof(char *) * map_data.x_max + 1);
	if (!visited)
		return (NULL);
	x = 0;
	y = 0;
	while (x < map_data.x_max)
	{
		visited[x] = malloc(sizeof(char) * map_data.y_max + 1);
		if (!visited)
			return (NULL);
		while (y < map_data.y_max)
		{
			visited[x][y] = '0';
			y++;
		}
		visited[x][y] = '\0';
		x++;
		y = 0;
	}
	visited[x] = NULL;
	return (visited);
}

int	find_path(t_map_data map_data, int x, int y, t_pos *target)
{
	if (x == target->x && y == target->y)
		return (1);
	if (map_data.map[x][y] != MAP_WALL && map_data.visited[x][y] == '0')
	{
		map_data.visited[x][y] = '1';
		if (find_path(map_data, x, y + 1, target) == 1)
			return (1);
		if (find_path(map_data, x + 1, y, target) == 1)
			return (1);
		if (find_path(map_data, x, y - 1, target) == 1)
			return (1);
		if (find_path(map_data, x - 1, y, target) == 1)
			return (1);
	}
	return (0);
}

int	check_one_path(t_map_data map_data, char char_target, int n_target)
{
	int		result;
	t_pos	*target;
	t_pos	*start;

	start = get_pos(map_data, MAP_START, 1);
	if (!start)
		return (-1);
	target = get_pos(map_data, char_target, n_target);
	if (!target)
	{
		free(start);
		return (-1);
	}
	map_data.visited = create_visited(map_data);
	if (!map_data.visited)
	{
		free(start);
		free(target);
		return (-1);
	}
	result = find_path(map_data, start->x, start->y, target);
	free(start);
	free(target);
	free_matrix(map_data.visited);
	return (result);
}

void	check_path(t_data *data)
{
	int	nb_items;
	int	i;
	int	result;

	nb_items = char_counter(data->map_data.map, MAP_ITEM);
	i = 0;
	while (i++ < nb_items)
	{
		result = check_one_path(data->map_data, MAP_ITEM, i);
		if (result != 1)
			free_matrix(data->map_data.map);
		if (result == -1)
			error_free("Malloc Error item", data);
		if (result == 0)
			error_free("Invalid Map (all items must be accessible)", data);
	}
	result = check_one_path(data->map_data, MAP_EXIT, 1);
	if (result != 1)
		free_matrix(data->map_data.map);
	if (result == -1)
		error_free("Malloc Error item", data);
	if (result == 0)
		error_free("Invalid Map (exit must be accessible)", data);
}
