/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:35:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/14 23:32:22 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == -1)
		return (1);
	set_data(&data, argv);
	init_philos(&data);
}
