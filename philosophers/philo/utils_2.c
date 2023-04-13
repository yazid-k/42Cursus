/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:08:42 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/12 20:04:03 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->monitor);
	if (philo->rules->end)
	{
		pthread_mutex_unlock(&philo->rules->monitor);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->monitor);
	return (0);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	print_action(t_philo philo, int action)
{
	pthread_mutex_lock(&philo.rules->print);
	if (action == FORK)
		printf("%ld %d has taken a fork\n", get_timestamp(), philo.id);
	else if (action == EAT)
		printf("%ld %d is eating\n", get_timestamp(), philo.id);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n", get_timestamp(), philo.id);
	else if (action == THINK)
		printf("%ld %d is thinking\n", get_timestamp(), philo.id);
	else if (action == DIE)
		printf("%ld %d died\n", get_timestamp(), philo.id);
	pthread_mutex_unlock(&philo.rules->print);
}

void	free_all(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->n)
		pthread_mutex_destroy(&rules->fork[i]);
	pthread_mutex_destroy(&rules->print);
	free(rules);
}
