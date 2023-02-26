/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:30:45 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/27 18:04:33 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		data->philo[i].id = i;
		data->philo[i].x_ate = 0;
		data->philo[i].l_fork = i;
		if (i + 1 == data->nb_philo)
			data->philo[i].r_fork = 0;
		else
			data->philo[i].r_fork = i + 1;
		data->philo[i].t_last_meal = 0;
		data->philo[i].data = data;
	}
	return (0);
}

int	init_mutexs(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(data->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(data->meal_check), NULL))
		return (1);
	if (pthread_mutex_init(&(data->m_died), NULL))
		return (1);
	if (pthread_mutex_init(&(data->m_all_ate), NULL))
		return (1);
	return (0);
}

int	init_data(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_death = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->all_ate = 0;
	data->died = 0;
	if (data->nb_philo < 1 || data->nb_philo > 250 || data->time_death < 1
		|| data->time_eat < 1 || data->time_sleep < 1)
		return (ERR_ARGS);
	if (av[5])
	{
		data->nb_eat = (ft_atoi(av[5]) - 1);
		if (data->nb_eat < 0)
			return (ERR_ARGS);
	}
	else
		data->nb_eat = -1;
	if (init_mutexs(data))
		return (ERR_MUTEX);
	init_philos(data);
	return (0);
}
