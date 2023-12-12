/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:06:19 by emiro-co          #+#    #+#             */
/*   Updated: 2023/12/11 16:04:53 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_index	index;

	init_index(argc, argv, &index);
	printf("nr de philos es: %i\n", list_size(index.philos));
	return (0);
}
