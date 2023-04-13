/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:58 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/13 11:43:55 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_end(t_rules *rules)
{
	int	i;
	int	min;

	pthread_mutex_lock(&rules->monitor);
	min = rules->philo[0].t_eat;
	i = -1;
	while (++i < rules->n)
	{
		if (get_timestamp() - rules->philo[i].last_meal > rules->death)
		{
			print_action(rules->philo[i], DIE);
			rules->end = 1;
			break ;
		}
		if (rules->philo[i].t_eat < min)
			min = rules->philo[i].t_eat;
	}
	if (min == rules->n_eat)
		rules->end = 1;
	pthread_mutex_unlock(&rules->monitor);
}

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->fork[min(philo->id - 1, philo->id
			% philo->rules->n)]);
	if (check_death(philo))
		return (pthread_mutex_unlock(&philo->rules->fork[min(philo->id - 1,
						philo->id % philo->rules->n)]), 0);
	print_action(*philo, FORK);
	pthread_mutex_lock(&philo->rules->fork[max(philo->id - 1, philo->id
			% philo->rules->n)]);
	if (check_death(philo))
	{
		pthread_mutex_unlock(&philo->rules->fork[min(philo->id - 1, philo->id
				% philo->rules->n)]);
		pthread_mutex_unlock(&philo->rules->fork[max(philo->id - 1, philo->id
				% philo->rules->n)]);
		return (0);
	}
	print_action(*philo, FORK);
	print_action(*philo, EAT);
	pthread_mutex_lock(&philo->rules->monitor);
	philo->t_eat++;
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->rules->monitor);
	usleep(1000 * philo->rules->eat);
	return (1);
}

int	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (check_death(philo))
		return (0);
	print_action(*philo, SLEEP);
	usleep(1000 * philo->rules->sleep);
	if (check_death(philo))
		return (0);
	print_action(*philo, THINK);
	usleep(5);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (!take_fork(philo))
			break ;
		if (!put_fork(philo))
			break ;
	}
	return (NULL);
}

void	start(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->n)
	{
		pthread_create(&rules->philo[i].thread, NULL, routine,
			&rules->philo[i]);
		usleep(5);
	}
	while (1)
	{
		update_end(rules);
		if (rules->end)
			break ;
	}
	i = -1;
	while (++i < rules->n)
		pthread_join(rules->philo[i].thread, NULL);
	free_all(rules);
}
