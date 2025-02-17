/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:12:10 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/17 18:21:18 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_status(t_philo *philo, t_data *data, char *message)
{
	if (is_philo_dead(data))
		return ;
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld %d %s\n",
		ft_get_current_time(data), philo->philo_id, message);
	pthread_mutex_unlock(&data->print_mutex);
}