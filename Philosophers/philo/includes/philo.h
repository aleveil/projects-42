/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:29:54 by aleveil           #+#    #+#             */
/*   Updated: 2023/01/27 18:02:03 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <string.h>

# define MSG_DEAD	0
# define MSG_EAT	1
# define MSG_SLEEP	2
# define MSG_THINK	3
# define MSG_FORK	4

# define ERR_ARGS	1
# define ERR_MUTEX	2
# define ERR_THREAD	3

typedef struct s_philo
{
	int					id;
	int					x_ate;
	int					l_fork;
	int					r_fork;
	long long			t_last_meal;
	struct s_data		*data;
	pthread_t			thread_id;
}		t_philo;

typedef struct s_data
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					died;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		m_died;
	pthread_mutex_t		m_all_ate;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_philo				philo[250];
}		t_data;

// init.c
int			init_mutexs(t_data *data);
int			init_data(t_data *data, char **av);
int			init_philos(t_data *data);

// routine.c
int			run_philo(t_data *data);
void		*routine(void *args);
void		ft_check_death(t_data *e, t_philo *p);
void		ft_eat(t_philo *philo);
void		start_exit(t_data *data);

// print.c
int			print_error(char *str);
int			set_error(int error);
void		print_action(t_data *data, int id, int check);
void		ft_alone(t_data *data, t_philo *philo);

// print_utils.c
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);

// utils.c
int			ft_atoi(const char *str);
long long	dif_time(long long time_start, long long time_end);
long long	timestamps(void);
void		check_wait(long long time, t_data *data);
void		destroy_mutexs(t_data *data);

// setget_mutex.c
void		set_died(t_data *data, int i);
int			get_died(t_data *data);
void		set_all_ate(t_data *data, int i);
int			get_all_ate(t_data *data);
#endif
