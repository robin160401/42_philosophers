/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:37:22 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/03 17:25:39 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		count;
	int		check_error;

	count = 0;
	num = (long)n;
	if (num < 0)
	{
		check_error = ft_putchar_fd('-', fd);
		if (check_error == -1)
			return (-1);
		count += check_error;
		num = -num;
	}
	if (num >= 10)
	{
		check_error = ft_putnbr_fd(num / 10, fd);
		if (check_error == -1)
			return (-1);
		count += check_error;
	}
	check_error = ft_putchar_fd((num % 10) + '0', fd);
	if (check_error == -1)
		return (-1);
	return (count += check_error, count);
}
// int main() {
// ft_putnbr_fd(-9, 1);
// }