/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:12:10 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/16 19:17:33 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_status(t_philo *philo, t_data *data, char *message)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld %d %s\n",
		ft_get_time_of_program(data), philo->philo_id, message);
	pthread_mutex_unlock(&data->print_mutex);
}
