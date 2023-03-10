/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:58 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/09 03:12:57 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_total_meals(t_philo *philo)
{
	int	i;
	int	min;

	min = 0;
	i = -1;
	if (!philo->rules->n_eat)
		return (-1);
	while (++i < philo->rules->n)
	{
		if (philo[i].t_eat < min)
			min = philo->rules->philo[i].t_eat;
	}
	return (min);
}

int	check_death_philo(t_philo *philo)
{
	if (get_timestamp() - philo->last_meal > philo->rules->death)
	{
		printf("%ld %d died\n", get_timestamp(), philo->id);
		return (1);
	}
	return (0);
}

void	take_fork(t_philo *philo)
{
	t_fork	*l;
	t_fork	*r;

	l = &philo->rules->fork[philo->l_fork - 1];
	r = &philo->rules->fork[philo->r_fork - 1];
	if (l->available)
	{
		pthread_mutex_lock(&l->mutex);
		l->available = 0;
		philo->forks++;
		print_action(*philo, FORK);
	}
	if (r->available)
	{
		pthread_mutex_lock(&r->mutex);
		r->available = 0;
		philo->forks++;
		print_action(*philo, FORK);
	}
}

void	put_fork(t_philo *philo)
{
	t_fork	*l;
	t_fork	*r;

	l = &philo->rules->fork[philo->l_fork - 1];
	r = &philo->rules->fork[philo->r_fork - 1];
	l->available = 1;
	philo->forks--;
	pthread_mutex_unlock(&l->mutex);
	r->available = 1;
	philo->forks++;
	pthread_mutex_unlock(&r->mutex);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_death_philo(philo)
		&& get_total_meals(philo) != philo->rules->n_eat)
	{
		take_fork(philo);
		if (philo->forks == 2)
		{
			print_action(*philo, EAT);
			philo->last_meal = get_timestamp();
			usleep(1000 * philo->rules->eat);
			put_fork(philo);
			print_action(*philo, SLEEP);
			usleep(1000 * philo->rules->sleep);
			print_action(*philo, THINK);
		}
	}
	return (NULL);
}

void	start(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->n)
	{
		if (rules->philo[i].forks != 2)
		{
			if (pthread_create(&rules->philo[i].thread, NULL,
					routine, &rules->philo[i]))
			{
				printf("Error in thread creation\n");
				return ;
			}
		}
	}
}
