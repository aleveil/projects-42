/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:15:18 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/10 15:30:29 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_xpm(void *mlx, t_img *xpm_img, char *xpm_path)
{
	xpm_img->img = mlx_xpm_file_to_image(mlx, xpm_path,
			&xpm_img->width, &xpm_img->height);
}

void	parse_xpm(t_data *data)
{
	void	*mlx;

	mlx = data->mlx_data.mlx;
	get_xpm(mlx, &data->xpm_data.img_ground, XPM_GROUND);
	get_xpm(mlx, &data->xpm_data.img_wall, XPM_WALL);
	get_xpm(mlx, &data->xpm_data.img_item, XPM_ITEM);
	get_xpm(mlx, &data->xpm_data.img_exit, XPM_EXIT);
	get_xpm(mlx, &data->xpm_data.img_player_up, XPM_PLAYER_UP);
	get_xpm(mlx, &data->xpm_data.img_player_down, XPM_PLAYER_DOWN);
	get_xpm(mlx, &data->xpm_data.img_player_left, XPM_PLAYER_LEFT);
	get_xpm(mlx, &data->xpm_data.img_player_right, XPM_PLAYER_RIGHT);
}

void	check_xpm(t_data *data)
{
	if (data->xpm_data.img_ground.img == NULL)
		error_free("XPM not found (ground.xpm)", data);
	if (data->xpm_data.img_wall.img == NULL)
		error_free("XPM not found (wall.xpm)", data);
	if (data->xpm_data.img_item.img == NULL)
		error_free("XPM not found (item.xpm)", data);
	if (data->xpm_data.img_exit.img == NULL)
		error_free("XPM not found (exit.xpm)", data);
	if (data->xpm_data.img_player_up.img == NULL)
		error_free("XPM not found (player_up.xpm)", data);
	if (data->xpm_data.img_player_down.img == NULL)
		error_free("XPM not found (player_down.xpm)", data);
	if (data->xpm_data.img_player_left.img == NULL)
		error_free("XPM not found (player_left.xpm)", data);
	if (data->xpm_data.img_player_right.img == NULL)
		error_free("XPM not found (player_right.xpm)", data);
}
