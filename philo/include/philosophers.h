/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:35:57 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/14 23:31:51 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo
{
	int				philo_id;
	struct s_data	*data;
	bool			fork_left;
	bool			fork_right;
	pthread_t		thread;
}					t_philo;

typedef struct s_data
{
	int		philos_and_forks;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_x;
	int		eaten_x;
	bool	philo_died;
	pthread_mutex_t	eat;
	pthread_mutex_t	sleep;
	pthread_mutex_t	die;
	t_philo	*philos;
}			t_data;

int		check_args(int argc, char **argv);
int		ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	set_data(t_data *data, char **argv);
void	init_philos(t_data *data);

#endif
