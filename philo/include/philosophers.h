/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:35:57 by rstumpf           #+#    #+#             */
/*   Updated: 2025/02/18 10:12:03 by rstumpf          ###   ########.fr       */
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
	unsigned long	last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	bool			philo_is_full;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philos_and_forks;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	start_time;
	int				must_eat_x;
	bool			philo_died;
	bool			philos_are_full;
	bool			start_routine;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	must_eat_mutex;
	pthread_mutex_t	forks[MAX_PHILOS];
	t_philo			philos[MAX_PHILOS];
}			t_data;

int				check_args(int argc, char **argv);
int				ft_putendl_fd(char *s, int fd);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			init_data(t_data *data, char **argv);
void			init_philos(t_data *data);
void			*routine(void *philo_thread);
unsigned long	ft_get_time(void);
void			ft_usleep(unsigned int milli_seconds, t_data *data);
unsigned long	ft_get_current_time(t_data *data);
void			update_last_meal_time(t_philo *philo, t_data *data);
int				create_philos_start_routine_add_monitor(t_data *data);
void			eat_r(t_philo *philo, t_data *data);
void			pick_forks(t_philo *philo, t_data *data);
void			is_eating(t_philo *philo, t_data *data);
void			finished_eating(t_philo *philo, t_data *data);
int				create_philos(t_data *data);
void			monitor(t_data *data);
void			philosopher_died(t_data *data, int i);
bool			is_philo_dead(t_data *data);
void			sleep_r(t_philo *philo, t_data *data);
void			print_status(t_philo *philo, t_data *data, char *message);
void			think_r(t_philo *philo, t_data *data);
void			init_forks(t_data *data);
void			destroy_forks(t_data *data);
void			run_monitor(t_data *data);
void			join_threads(t_data *data);
void			destroy_mutexes(t_data *data);
bool			are_philos_full(t_data *data);
bool			check_if_philos_are_full(t_data	*data);

#endif