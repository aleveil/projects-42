/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:30:00 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/10 15:55:26 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_img(t_data *data, t_img img, int y, int x)
{
	void	*mlx;
	void	*mlx_win;

	mlx = data->mlx_data.mlx;
	mlx_win = data->mlx_data.mlx_win;
	mlx_put_image_to_window(mlx, mlx_win,
		img.img, CELL_SIZE * y, CELL_SIZE * x);
}

void	render_char(t_data *data, char c, int y, int x)
{
	if (c == MAP_SPACE)
		render_img(data, data->xpm_data.img_ground, y, x);
	if (c == MAP_WALL)
		render_img(data, data->xpm_data.img_wall, y, x);
	if (c == MAP_ITEM)
	{
		render_img(data, data->xpm_data.img_ground, y, x);
		render_img(data, data->xpm_data.img_item, y, x);
	}
	if (c == MAP_EXIT)
		render_img(data, data->xpm_data.img_exit, y, x);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_data.x_max)
	{
		while (y < data->map_data.y_max)
		{
			render_char(data, data->map_data.map[x][y], y, x);
			y++;
		}
		y = 0;
		x++;
	}
}

void	render_player(t_data *data, t_img plyr_img)
{
	render_img(data, plyr_img, data->plyr_data.y, data->plyr_data.x);
}

void	render_all(t_data *data, t_img plyr_img)
{
	render_map(data);
	render_player(data, plyr_img);
	print_move(data);
}
