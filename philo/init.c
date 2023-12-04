/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:49:30 by emiro-co          #+#    #+#             */
/*   Updated: 2023/12/04 18:05:50 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_index	init_index(int argc, char **argv)
{
	t_index	index;
	int		err_times;

	if (argc == 5 || argc == 6)
	{
		err_times = init_times(index, argv, argc);
		if (err_times != 0)
		{
			index = NULL;
			return (index);
		}
	}
	else
		printf("Error\n");
}

int	init_times(t_index *index, char **argv, int argc)
{
	index->ph_num = ft_atoi(argv[1]);
	if (index->ph_num == 0)
		return (printf("%s\n", ARG1), 1);
	index->tt_die = ft_atoi(argv[2]);
	if (index->tt_die == 0)
		return (printf("%s\n", ARG2), 2);
	index->tt_eat = ft_atoi(argv[3]);
	if (index->tt_eat == 0)
		return (printf("%s\n", ARG3), 3);
	index->tt_sleep = ft_atoi(argv[4]);
	if (index->tt_sleep == 0)
		return (printf("%s\n", ARG4), 4);
	if (argc == 6)
	{
		index->n_eats = ft_atoi(argv[5]);
		if (index->n_eats == 0)
		{
			return (printf("%s\n", ARG5), 5);
		}
	}
	return (0);
}
