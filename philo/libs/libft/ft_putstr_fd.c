/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:48:43 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/03 17:24:59 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;
	int	check_errors;

	check_errors = 0;
	count = 0;
	if (s == NULL)
		return (count += write(fd, "(null)", 6));
	while (*s)
	{
		check_errors = write(fd, s, 1);
		if (check_errors < 0)
			return (-1);
		count += check_errors;
		s++;
	}
	return (count);
}
