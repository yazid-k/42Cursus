/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:08:42 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/19 20:48:58 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	{
		pthread_mutex_destroy(&rules->fork[i].mutex);
		pthread_detach(rules->philo[i].thread);
	}
	pthread_mutex_destroy(&rules->print);
	free(rules);
}

void	update_fork(t_fork *fork, t_philo *philo)
{
	pthread_mutex_lock(&fork->mutex);
	fork->available = 0;
	philo->forks++;
	print_action(*philo, FORK);
	pthread_mutex_unlock(&fork->mutex);
}
