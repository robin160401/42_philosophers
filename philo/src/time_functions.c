/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:49:15 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/20 15:14:03 by rstumpf          ###   ########.fr       */
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
		if (is_philo_dead(data) || are_philos_full(data))
			break ;
		usleep(100);
	}
}
