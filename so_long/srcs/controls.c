/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:02:32 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/10 16:04:21 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move(t_data *data, int x_dir, int y_dir, t_img img)
{
	char	**map;
	int		x_target;
	int		y_target;

	map = data->map_data.map;
	x_target = data->plyr_data.x + x_dir;
	y_target = data->plyr_data.y + y_dir;
	if (map[x_target][y_target] != MAP_WALL)
	{
		ft_putstr_fd("move : ", 1);
		ft_putnbr_fd(data->plyr_data.move, 1);
		ft_putstr_fd("\n", 1);
		data->plyr_data.x = x_target;
		data->plyr_data.y = y_target;
		data->plyr_data.move++;
		if (map[data->plyr_data.x][data->plyr_data.y] == MAP_ITEM)
		{
			map[data->plyr_data.x][data->plyr_data.y] = MAP_SPACE;
			data->plyr_data.items++;
		}
		if (map[data->plyr_data.x][data->plyr_data.y] == MAP_EXIT
			&& data->plyr_data.items == data->map_data.nb_items)
			finish(data);
	}
	render_all(data, img);
}

int	key_hook(int key_code, t_data *data)
{
	if (key_code == KEY_W)
		move(data, -1, 0, data->xpm_data.img_player_up);
	if (key_code == KEY_A)
		move(data, 0, -1, data->xpm_data.img_player_left);
	if (key_code == KEY_S)
		move(data, 1, 0, data->xpm_data.img_player_down);
	if (key_code == KEY_D)
		move(data, 0, 1, data->xpm_data.img_player_right);
	if (key_code == KEY_ESC)
		finish(data);
	return (0);
}
