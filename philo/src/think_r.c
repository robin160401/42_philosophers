/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:10:56 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/16 19:18:32 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	think_r(t_philo *philo, t_data *data)
{
	print_status(philo, data, "is thinking");
}
