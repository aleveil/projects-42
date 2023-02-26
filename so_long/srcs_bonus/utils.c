/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:25:35 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 16:25:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_data *data)
{
	char	*str;

	str = ft_itoa(data->plyr_data.move);
	mlx_string_put(data->mlx_data.mlx, data->mlx_data.mlx_win, 5, 10,
		0xFFFFFF, str);
	free(str);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_data(t_data *data)
{
	free(data);
}

void	error_free(char *str, t_data *data)
{
	free_data(data);
	error(str);
}

void	error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
