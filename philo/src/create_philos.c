/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:37:06 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/17 18:00:23 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	create_philos_start_routine_add_monitor(t_data *data)
{
	create_philos(data);
	run_monitor(data);
	return (0);
}

int	create_philos(t_data *data)
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
	return (0);
}
