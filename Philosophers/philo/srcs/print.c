/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:32:12 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/27 18:05:57 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	set_error(int error)
{
	if (error == ERR_ARGS)
		return (print_error("Wrong Arguments"));
	if (error == ERR_MUTEX)
		return (print_error("Error inializing mutuex"));
	if (error == ERR_THREAD)
		return (print_error("Error inializing thread"));
	return (1);
}

void	print_action(t_data *data, int id, int check)
{
	pthread_mutex_lock(&(data->writing));
	if (get_died(data) == 0)
	{
		printf("%lli ", timestamps() - data->first_timestamp);
		if (check == MSG_DEAD)
			printf("%d %s\n", id + 1, "died");
		if (check == MSG_EAT)
			printf("%d %s\n", id + 1, "is eating");
		if (check == MSG_SLEEP)
			printf("%d %s\n", id + 1, "is sleeping");
		if (check == MSG_THINK)
			printf("%d %s\n", id + 1, "is thinking");
		if (check == MSG_FORK)
			printf("%d %s\n", id + 1, "has taken a fork");
	}
	pthread_mutex_unlock(&(data->writing));
}

void	ft_alone(t_data *data, t_philo *philo)
{
	print_action(data, philo->id, MSG_FORK);
	check_wait(data->time_eat, data);
}
