/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:49:15 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/15 16:32:20 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

unsigned int	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (unsigned int)1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(unsigned int sleep_time)
{
	unsigned int	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(500);
}
