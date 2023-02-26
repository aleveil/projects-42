/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:43:36 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 15:43:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_data	*set_struct(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error("Malloc Error data");
	return (data);
}

void	set_player(t_data *data)
{
	t_pos	*player_pos;

	player_pos = get_pos(data->map_data, MAP_START, 1);
	data->plyr_data.x = player_pos->x;
	data->plyr_data.y = player_pos->y;
	free(player_pos);
	data->plyr_data.move = 0;
	data->plyr_data.items = 0;
	data->map_data.map[data->plyr_data.x][data->plyr_data.y] = MAP_SPACE;
}

int	finish(t_data *data)
{
	free_matrix(data->map_data.map);
	free_data(data);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = set_struct();
	if (argc != 2)
		error_free("Invalid argument (./so_long [filename].ber)", data);
	parse_map(argv[1], data);
	check_map(data);
	check_path(data);
	data->mlx_data.mlx = mlx_init();
	parse_xpm(data);
	check_xpm(data);
	set_player(data);
	data->mlx_data.mlx_win = mlx_new_window(data->mlx_data.mlx,
			data->map_data.y_max * CELL_SIZE,
			data->map_data.x_max * CELL_SIZE,
			WIN_NAME);
	render_all(data, data->xpm_data.img_player_down);
	mlx_hook(data->mlx_data.mlx_win, EVENT_KEYDOWN, 0, key_hook, data);
	mlx_hook(data->mlx_data.mlx_win, EVENT_DESTROY, 0, finish, data);
	mlx_loop(data->mlx_data.mlx);
}
