/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:04:47 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/16 20:24:45 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	sleep_r(t_philo *philo, t_data *data)
{
	print_status(philo, data, "is sleeping");
	ft_usleep(data->time_to_sleep, data);
}
