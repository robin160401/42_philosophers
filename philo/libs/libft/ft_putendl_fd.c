/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:48:43 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/03 17:25:55 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (*s)
	{
		count += write(fd, s, 1);
		s++;
	}
	count += write(fd, "\n", 1);
	return (count);
}
