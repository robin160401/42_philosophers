/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:17:58 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/17 18:22:44 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *philo_thread)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_thread;
	data = philo->data;
	if (philo->philo_id % 2 != 0)
		ft_usleep(data->time_to_eat / 2, data);
	while (is_philo_dead(data) == false)
	{
		if (is_philo_dead(data))
			return (NULL);
		eat_r(philo, data);
		if (is_philo_dead(data))
			return (NULL);
		sleep_r(philo, data);
		if (is_philo_dead(data))
			return (NULL);
		think_r(philo, data);
		if (is_philo_dead(data))
			return (NULL);
	}
	return (NULL);
}

void	wait_start_signal(t_data *data)
{
	pthread_mutex_lock(&data->start_mutex);
	while (data->start_routine == false)
	{
		pthread_mutex_unlock(&data->start_mutex);
		usleep(100);
		pthread_mutex_lock(&data->start_mutex);
	}
}

bool	is_philo_dead(t_data *data)
{
	bool	result;

	pthread_mutex_lock(&data->death_mutex);
	result = data->philo_died;
	pthread_mutex_unlock(&data->death_mutex);
	return (result);
}
