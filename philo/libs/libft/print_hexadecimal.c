/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:38:34 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/03 18:09:32 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexadecimal(int islower, unsigned long x)
{
	int		count;
	char	*hexadecimal;
	int		check_error;

	count = 0;
	check_error = 0;
	if (islower)
		hexadecimal = "0123456789abcdef";
	else
		hexadecimal = "0123456789ABCDEF";
	if (x < 16)
		return (ft_putchar_fd(hexadecimal[x], 1));
	else
	{
		count = print_hexadecimal(islower, x / 16);
		if (count == -1)
			return (-1);
		check_error = print_hexadecimal(islower, x % 16);
		if (check_error == -1)
			return (-1);
		count += check_error;
		return (count);
	}
}
