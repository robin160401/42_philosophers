/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:56:39 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/04 14:50:54 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_createline(char *buffer)
{
	int		len;
	int		i;
	char	*output_line;

	len = 0;
	i = 0;
	while (buffer[len] != '\n' && buffer[len])
		len++;
	if (buffer[len] == '\n')
		len += 1;
	output_line = malloc(sizeof(char) * (len + 1));
	if (!output_line)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
	{
		output_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		output_line[i] = '\n';
		i++;
	}
	output_line[i] = '\0';
	return (output_line);
}
