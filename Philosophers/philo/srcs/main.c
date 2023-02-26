/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:29:18 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/27 18:05:11 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9' || ft_strlen(av[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		ret;
	t_data	data;

	if ((ac != 5 && ac != 6) || !is_digit(av))
		return (set_error(ERR_ARGS));
	ret = init_data(&data, av);
	if (ret > 0)
		return (set_error(ret));
	if (run_philo(&data))
	{
		destroy_mutexs(&data);
		return (print_error("Threads wasn't create"));
	}
	return (0);
}
