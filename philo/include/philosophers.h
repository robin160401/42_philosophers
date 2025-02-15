/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:35:57 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/15 16:35:12 by rstumpf          ###   ########.fr       */
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
# define MAX_PHILOS 200

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philos_and_forks;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				must_eat_x;
	int				eaten_x;
	bool			philo_died;
	pthread_mutex_t	start_mutex;
	bool			start_routine;
	t_philo			philos[MAX_PHILOS];
}			t_data;

int				check_args(int argc, char **argv);
int				ft_putendl_fd(char *s, int fd);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			init_data(t_data *data, char **argv);
void			init_philos(t_data *data);
void			*routine(void *philo_thread);
unsigned int	ft_get_time(void);
void			ft_usleep(unsigned int sleep_time);
int				create_philos_start_routine(t_data *data);
void			wait_start_signal(t_philo *philo, t_data *data);

#endif
