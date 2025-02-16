/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:41:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/16 19:47:08 by rstumpf          ###   ########.fr       */
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
