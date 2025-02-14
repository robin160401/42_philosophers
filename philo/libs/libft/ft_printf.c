/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:13:30 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/03 17:26:32 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	print_different_formats(const char *s, va_list ap)
{
	if (*s == '%')
		return (ft_putchar_fd('%', 1));
	else if (*s == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (*s == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (*s == 'd')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (*s == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (*s == 'u')
		return (ft_putunsignednbr_fd(va_arg(ap, int), 1));
	else if (*s == 'x')
		return (print_hexadecimal(1, va_arg(ap, unsigned int)));
	else if (*s == 'X')
		return (print_hexadecimal(0, va_arg(ap, unsigned int)));
	else if (*s == 'p')
		return (check_error_print_address(va_arg(ap, unsigned long)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count_output;
	int		print_output;

	count_output = 0;
	print_output = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_output = print_different_formats(format++, ap);
			count_output += print_output;
		}
		else if (*format != '\0')
		{
			print_output = ft_putchar_fd(*format++, 1);
			count_output += print_output;
		}
		if (print_output == -1)
			return (-1);
	}
	va_end(ap);
	return (count_output);
}

// int	main(void)
// {
// 	int	count;
// 	int count2;
// 	// int hexa = -12;
// 	// count2 = 20;

// 	// ft_printf("My printf %x \n", -12);
// 	// printf("Real printf %i \n", -1111);
// 	ft_printf("My printf %u \n", -1111);
// 	printf("Real printf %u \n", -1111);
// 	// count = ft_printf("My printf %%%% \n");
// 	// printf("My count %d \n", count);
// 	// count2 = printf("Real printf %%%% \n");
// 	// printf("Original count %d \n", count2);
// }
