/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_print_address.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:54:08 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/03 18:09:45 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_address(unsigned long p)
{
	int		count;
	char	*hexadecimal;
	int		check_error;

	count = 0;
	check_error = 0;
	hexadecimal = "0123456789abcdef";
	if (p < 16)
		return (ft_putchar_fd(hexadecimal[p], 1));
	else
	{
		count = print_address(p / 16);
		if (count == -1)
			return (-1);
		check_error = print_address(p % 16);
		if (check_error == -1)
			return (-1);
		count += check_error;
		return (count);
	}
}

int	check_error_print_address(unsigned long p)
{
	int	check_error;

	check_error = 0;
	check_error = write(1, "0x", 2);
	if (check_error != -1)
		return (print_address(p) + 2);
	else
		return (-1);
}
