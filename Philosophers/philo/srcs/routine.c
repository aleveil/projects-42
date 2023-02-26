/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:31:16 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/27 16:37:37 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(data->philo[i].thread_id, NULL);
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->writing));
	pthread_mutex_destroy(&(data->meal_check));
	pthread_mutex_destroy(&(data->m_died));
	pthread_mutex_destroy(&(data->m_all_ate));
}

void	ft_check_death(t_data *d, t_philo *p)
{
	int	i;

	while (!(get_all_ate(d)))
	{
		i = -1;
		while (++i < d->nb_philo && !(get_died(d)))
		{
			pthread_mutex_lock(&(d->meal_check));
			if (dif_time(p[i].t_last_meal, timestamps()) > d->time_death)
			{
				print_action(d, i, MSG_DEAD);
				set_died(d, 1);
			}
			pthread_mutex_unlock(&(d->meal_check));
			usleep(10);
		}
		if (get_died(d))
			break ;
		i = 0;
		while (d->nb_eat != -1 && i < d->nb_philo && p[i].x_ate >= d->nb_eat)
			i++;
		if (i == d->nb_philo)
			set_all_ate(d, 1);
	}
}

void	ft_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(data->forks[philo->l_fork]));
		print_action(data, philo->id, MSG_FORK);
		pthread_mutex_lock(&(data->forks[philo->r_fork]));
		print_action(data, philo->id, MSG_FORK);
	}
	else
	{
		pthread_mutex_lock(&(data->forks[philo->r_fork]));
		print_action(data, philo->id, MSG_FORK);
		pthread_mutex_lock(&(data->forks[philo->l_fork]));
		print_action(data, philo->id, MSG_FORK);
	}
	pthread_mutex_lock(&(data->meal_check));
	print_action(data, philo->id, MSG_EAT);
	philo->t_last_meal = timestamps();
	pthread_mutex_unlock(&(data->meal_check));
	check_wait(data->time_eat, data);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(data->forks[philo->l_fork]));
	pthread_mutex_unlock(&(data->forks[philo->r_fork]));
}

void	*routine(void *args)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->id % 2)
		usleep(20);
	if (data->nb_philo == 1)
	{
		ft_alone(data, philo);
		return (NULL);
	}
	while (!(get_died(data)) || get_all_ate(data) < 1)
	{
		ft_eat(philo);
		if (get_all_ate(data) || get_died(data))
			break ;
		print_action(data, philo->id, MSG_SLEEP);
		check_wait(data->time_sleep, data);
		print_action(data, philo->id, MSG_THINK);
	}
	return (NULL);
}

int	run_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	data->first_timestamp = timestamps();
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, routine, &(philo[i])))
		{
			set_error(ERR_THREAD);
			return (1);
		}
		pthread_mutex_lock(&(data->meal_check));
		philo[i].t_last_meal = timestamps();
		pthread_mutex_unlock(&(data->meal_check));
		i++;
	}
	ft_check_death(data, data->philo);
	start_exit(data);
	return (0);
}
