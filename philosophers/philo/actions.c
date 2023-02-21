/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:58 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/19 20:55:14 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_sleep(t_philo *philo)
{
	print_action(*philo, SLEEP);
	usleep(1000 * philo->rules->sleep);
	print_action(*philo, THINK);
}

void	eat(t_philo *philo)
{
	print_action(*philo, EAT);
	philo->t_eat++;
	usleep(1000 * philo->rules->eat);
	p_sleep(philo);
}

void	*take_fork(void *arg)
{
	t_philo	*philo;
	t_fork	*l;
	t_fork	*r;

	philo = (t_philo *)arg;
	l = &philo->rules->fork[philo->l_fork];
	r = &philo->rules->fork[philo->r_fork];
	if (l->available)
		update_fork(l, philo);
	if (r->available)
		update_fork(r, philo);
	if (philo->forks == 2)
		eat(philo);
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
					take_fork, &rules->philo[i]))
			{
				printf("Error in thread creation\n");
				return ;
			}
			if (pthread_join(rules->philo[i].thread, NULL))
			{
				printf("Error in thread join\n");
				return ;
			}
		}
	}
}
