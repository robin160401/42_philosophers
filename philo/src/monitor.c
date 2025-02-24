/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:29:10 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/17 19:49:55 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	monitor(t_data *data)
{
	int				i;
	unsigned long	time_of_last_meal;

	i = 0;
	while (i < data->philos_and_forks)
	{
		pthread_mutex_lock(&data->meal_mutex);
		time_of_last_meal = data->philos[i].last_meal_time;
		if (are_philos_full(data))
			return ;
		if (ft_get_current_time(data) - time_of_last_meal > data->time_to_die)
		{
			philosopher_died(data, i);
			pthread_mutex_unlock(&data->meal_mutex);
			return ;
		}
		if (data->philos[i].meals_eaten == data->must_eat_x)
			data->philos[i].philo_is_full = true;
		pthread_mutex_unlock(&data->meal_mutex);
		i++;
	}
}

void	philosopher_died(t_data *data, int i)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld %d died\n", ft_get_current_time(data),
		data->philos[i].philo_id);
	pthread_mutex_unlock(&data->print_mutex);
	pthread_mutex_lock(&data->death_mutex);
	data->philo_died = true;
	pthread_mutex_unlock(&data->death_mutex);
}

bool	check_if_philos_are_full(t_data	*data)
{
	int				i;

	i = 0;
	while (i < data->philos_and_forks)
	{
		if (data->philos[i].philo_is_full == false)
			return (false);
		i++;
	}
	pthread_mutex_lock(&data->must_eat_mutex);
	data->philos_are_full = true;
	pthread_mutex_unlock(&data->must_eat_mutex);
	return (true);
}

void	run_monitor(t_data *data)
{
	usleep(2000);
	while (1)
	{
		monitor(data);
		if (data->philo_died)
			break ;
		check_if_philos_are_full(data);
		if (data->philos_are_full)
			break ;
		usleep(1000);
	}
}
