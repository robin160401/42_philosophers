/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:50:18 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/08 19:05:57 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_line(int fd, char *output, char *leftover)
{
	ssize_t		bytes_read;
	char		*temp;

	while (!ft_strchr(output, '\n'))
	{
		bytes_read = read(fd, leftover, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (leftover[0] == 0)
				return (free(output), output = NULL, NULL);
			ft_bzero(leftover, BUFFER_SIZE + 1);
			temp = ft_createline(output);
			free(output);
			return (temp);
		}
		if (bytes_read == -1)
			return (free(output), ft_bzero(leftover, BUFFER_SIZE + 1), NULL);
		leftover[bytes_read] = '\0';
		temp = ft_strjoin(output, leftover);
		free(output);
		if (!temp)
			return (NULL);
		output = temp;
	}
	return (output);
}

void	ft_update_leftover(char *leftover)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (leftover[i] != '\n' && leftover[i])
		i++;
	while (leftover[i])
	{
		leftover[j] = leftover[i + 1];
		i++;
		j++;
	}
	leftover[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	leftover[100][BUFFER_SIZE + 1];
	char		*output;
	char		*new_output;

	output = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	output = ft_strjoin("", leftover[fd]);
	if (!output)
		return (NULL);
	output = ft_read_line(fd, output, leftover[fd]);
	if (!output)
		return (NULL);
	new_output = ft_createline(output);
	free(output);
	output = NULL;
	if (!new_output)
		return (NULL);
	ft_update_leftover(leftover[fd]);
	return (new_output);
}
