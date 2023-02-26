/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setget_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:16:50 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/27 16:37:37 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_died(t_data *data, int i)
{
	pthread_mutex_lock(&(data->m_died));
	data->died = i;
	pthread_mutex_unlock(&(data->m_died));
}

int	get_died(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(data->m_died));
	i = data->died;
	pthread_mutex_unlock(&(data->m_died));
	return (i);
}

void	set_all_ate(t_data *data, int i)
{
	pthread_mutex_lock(&(data->m_all_ate));
	data->all_ate = i;
	pthread_mutex_unlock(&(data->m_all_ate));
}

int	get_all_ate(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(data->m_all_ate));
	i = data->all_ate;
	pthread_mutex_unlock(&(data->m_all_ate));
	return (i);
}
