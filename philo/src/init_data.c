/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:17:48 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/15 15:52:18 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_data(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->philos_and_forks = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat_x = -1;
	if (argv[5])
		data->must_eat_x = ft_atoi(argv[5]);
	data->philo_died = false;
	pthread_mutex_init(&data->start_mutex, NULL);
	data->start_routine = false;
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_and_forks)
	{
		data->philos[i].data = data;
		data->philos[i].philo_id = i + 1;
		data->philos[i].meals_eaten = 0;
		i++;
	}
}
