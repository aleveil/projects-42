/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:50:05 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 15:50:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_map_data
{
	char	**map;
	char	**visited;
	int		x_max;
	int		y_max;
	int		nb_items;
}	t_map_data;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_data;

typedef struct s_xpm_data
{
	t_img	img_ground;
	t_img	img_wall;
	t_img	img_item;
	t_img	img_exit;
	t_img	img_player_up;
	t_img	img_player_down;
	t_img	img_player_left;
	t_img	img_player_right;

}	t_xpm_data;

typedef struct s_plyr_data
{
	int	x;
	int	y;
	int	move;
	int	items;
}	t_plyr_data;

typedef struct s_data
{
	t_map_data	map_data;
	t_mlx_data	mlx_data;
	t_xpm_data	xpm_data;
	t_plyr_data	plyr_data;
}	t_data;

# define FALSE	0
# define TRUE	1

# define WIN_NAME	"so_long"

# define EVENT_KEYDOWN 2
# define EVENT_DESTROY 17

# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define KEY_ESC	53

# define CELL_SIZE	64

# define MAP_SPACE	'0'
# define MAP_WALL	'1'
# define MAP_ITEM	'C'
# define MAP_EXIT	'E'
# define MAP_START	'P'

# define XPM_GROUND			"img/ground.xpm"
# define XPM_WALL			"img/wall.xpm"
# define XPM_ITEM			"img/item.xpm"
# define XPM_EXIT			"img/exit.xpm"
# define XPM_PLAYER_UP		"img/player_up.xpm"
# define XPM_PLAYER_DOWN	"img/player_down.xpm"
# define XPM_PLAYER_LEFT	"img/player_left.xpm"
# define XPM_PLAYER_RIGHT	"img/player_right.xpm"

# define BUFFER_SIZE	1

// main.c
int		finish(t_data *data);

// get_next_line.c
char	*get_next_line(int fd);

// parsing.c
char	**get_map(int fd, t_data *data);
int		is_check_ber(char *filename);
void	parse_map(char	*filename, t_data *data);

// parsing_utils.c
void	close_free(int fd, char *all_lines);
char	*ft_strjoin_free(char *s1, char *s2);
int		is_check_ber(char *filename);

// map_checker.c
int		is_char_check(char	**map);
int		is_rect_check(char	**map);
int		is_close_check(t_map_data map_data);
int		is_count_check(t_data *data);
void	check_map(t_data *data);

// map_checker_utils.c
int		is_char_valid(char c);
int		is_lines_closed(t_map_data map_data);
int		is_cols_closed(t_map_data map_data);
int		char_counter(char **matrix, char c);

// pathfinding.c
int		find_path(t_map_data map_data, int x, int y, t_pos *target);
void	check_path(t_data *data);

// pathfinding_utils.c
t_pos	*create_pos(int x, int y);
t_pos	*get_pos(t_map_data map_data, char c, int n);

// xpm.c
void	parse_xpm(t_data *data);
void	check_xpm(t_data *data);

// rendering.c
void	render_all(t_data *data, t_img plyr_img);

// controls.c
int		key_hook(int key_code, t_data *data);

// utils.c
void	print_move(t_data *data);
void	free_data(t_data *data);
void	error(char *str);
void	error_free(char *str, t_data *data);
void	free_matrix(char **matrix);

#endif
