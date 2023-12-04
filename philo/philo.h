/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:59:48 by emiro-co          #+#    #+#             */
/*   Updated: 2023/12/04 17:53:39 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

/* ROUTINE MSG */
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

/* ERROR MSG */
# define NUM_ARGS "ERROR: The number of argments must be 4 or 5"
# define ARG1 "ERROR: There is a mistake in number of philosophers"
# define ARG2 "ERROR: There is a mistake in time to die"
# define ARG3 "ERROR: There is a mistake in time to eat"
# define ARG4 "ERROR: There is a mistake in time to sleep"
# define ARG5 "ERROR: There is a mistake in number of times each \
philosopher must eat"

/* MAIN STRUCT */
typedef struct s_index
{
	pthread_t		*tid;
	int				ph_num;
	int				n_eats;
	int				dead;
	int				finished;
	t_philo			*philos;
	u_int64_t		tt_die;
	u_int64_t		tt_eat;
	u_int64_t		tt_sleep;
	u_int64_t		ini_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_index;

/* PHILO INI */
typedef struct s_philo
{
	struct s_index	*index;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

/* INIT.C */
t_index	init_index(int argc, char **argv);
int		init_times(t_index index, char **argv, int argc);

/* UTILS.C */
int		ft_atoi(const char *str);

#endif