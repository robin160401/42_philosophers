/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:06 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/15 16:09:04 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	create_philos_start_routine(t_data *data)
{
	create_philos(data);
	start_routine(data);
	return (0);
}

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_and_forks)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&routine, (void*)&data->philos[i]))
			return (ft_putendl_fd("Error creating Threads", 2), -1);
		i++;
	}
}

void	start_routine(t_data *data)
{
	usleep(1000);
	pthread_mutex_lock(&data->start_mutex);
	data->start_routine = true;
	pthread_mutex_unlock(&data->start_mutex);
}
