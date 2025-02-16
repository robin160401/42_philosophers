/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:03:07 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/16 21:00:43 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eat_r(t_philo *philo, t_data *data)
{
	pick_forks(philo, data);
	update_last_meal_time(philo, data);
	is_eating(philo, data);
	finished_eating(philo, data);
}

void	pick_forks(t_philo *philo, t_data *data)
{
	if (data->philos_and_forks == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, data, "has taken a fork");
		ft_usleep(data->time_to_die + 10, data);
		pthread_mutex_unlock(philo->left_fork);
		return ;
    }
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, data, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, data, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, data, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, data, "has taken a fork");
	}
}

void	is_eating(t_philo *philo, t_data *data)
{
	print_status(philo, data, "is eating");
	ft_usleep(data->time_to_eat, data);
}

void	finished_eating(t_philo *philo, t_data *data)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&data->meal_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meal_mutex);
}
