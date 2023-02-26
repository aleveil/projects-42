/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:22:54 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/10 15:29:02 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_pos(t_pos *start, t_pos *target)
{
	free(start);
	free(target);
}

t_pos	*create_pos(int x, int y)
{
	t_pos	*pos;

	pos = malloc(sizeof(pos));
	if (!pos)
		return (NULL);
	pos->x = x;
	pos->y = y;
	return (pos);
}

t_pos	*get_pos(t_map_data map_data, char c, int n)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (map_data.map[x])
	{
		while (map_data.map[x][y])
		{
			if (map_data.map[x][y] == c)
			{
				i++;
				if (i == n)
					return (create_pos(x, y));
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (NULL);
}
