/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:41:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/18 10:10:07 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	destroy_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_and_forks)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

void	destroy_mutexes(t_data *data)
{
	destroy_forks(data);
	ft_usleep(100, data);
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->sleep_mutex);
}
