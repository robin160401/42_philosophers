/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:35:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/17 19:54:01 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == -1)
		return (1);
	init_data(&data, argv);
	init_philos(&data);
	if (create_philos_start_routine_add_monitor(&data) == -1)
		return (1);
	join_threads(&data);
	destroy_mutexes(&data);
}
