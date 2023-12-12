/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:49:30 by emiro-co          #+#    #+#             */
/*   Updated: 2023/12/11 17:58:17 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_index(int argc, char **argv, t_index *index)
{
	if (argc == 5 || argc == 6)
	{
		if (init_times(index, argv, argc))
			return (1);	
	}
	else
		return (printf("%s\n", NUM_ARGS), 1);
	index->philos = malloc(sizeof(t_philo));
	init_list(index->philos, index->ph_num, index);
	index->tid = malloc(sizeof(pthread_t) * index->ph_num);
	index->forks = malloc(sizeof(int) * (index->ph_num));
	if (!index->philos || !index->forks || !index->tid)
		return (/*free_all(index), */1);
	return (0);
}

int	init_list(t_philo *philos, int size, t_index *index)
{
	(void)index;
	while (--size)
	{
		if (pthread_create(philos->t1, NULL, &routine, index) != 0)
			return (1);
		philos->next = malloc(sizeof(t_philo));
		if (!philos->next)
			return (/*free_all(index), */1);
		philos = philos->next;
	}
	philos->next = NULL;
	return (0);
}

int	init_times(t_index *index, char **argv, int argc)
{
	index->ph_num = ft_atoi(argv[1]);
	if (index->ph_num == 0 || index->ph_num > 150)
		return (printf("%s\n", ARG1), 1);
	index->tt_die = ft_atoi(argv[2]);
	if (index->tt_die < 20 || index->tt_die > 60000)
		return (printf("%s\n", ARG2), 1);
	index->tt_eat = ft_atoi(argv[3]);
	if (index->tt_eat < 20 || index->tt_eat > 60000)
		return (printf("%s\n", ARG3), 1);
	index->tt_sleep = ft_atoi(argv[4]);
	if (index->tt_sleep < 20 || index->tt_sleep > 60000)
		return (printf("%s\n", ARG4), 1);
	if (argc == 6)
	{
		index->n_eats = ft_atoi(argv[5]);
		if (index->n_eats == 0)
		{
			return (printf("%s\n", ARG5), 1);
		}
	}
	return (0);
}
