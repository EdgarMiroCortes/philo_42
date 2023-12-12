/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:16:20 by emiro-co          #+#    #+#             */
/*   Updated: 2023/12/11 16:17:57 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

int	list_size(t_philo *philos)
{
	if (philos == NULL)
		return (0);
	return (1 + list_size(philos->next));
}

/* void	free_all(t_index *index)
{
	if (index)
	{
		if (index->philos)
		{
			while (index->ph_num--)
				free (index->philos[index->ph_num]);
			
		}
	}
} */