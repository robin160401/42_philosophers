/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:49:15 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/17 14:28:59 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

unsigned long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

unsigned long	ft_get_current_time(t_data *data)
{
	return (ft_get_time() - data->start_time);
}

void	ft_usleep(unsigned int milli_seconds, t_data *data)
{
	unsigned int	start;

	start = ft_get_current_time(data);
	while ((ft_get_current_time(data) - start) < milli_seconds)
	{
		if (is_philo_dead(data))
            break ;
		usleep(500);
	}
}

void	update_last_meal_time(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_meal_time = ft_get_current_time(data);
	pthread_mutex_unlock(&data->meal_mutex);
}
