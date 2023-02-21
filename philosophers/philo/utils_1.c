/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:34:33 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/19 20:36:39 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(void)
{
	static unsigned long	time = 0;
	struct timeval			tv;

	gettimeofday(&tv, NULL);
	if (!time)
	{
		time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		return (time);
	}
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - time);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

t_fork	init_fork(int id)
{
	t_fork			fork;

	fork.id = id;
	fork.available = 1;
	pthread_mutex_init(&fork.mutex, NULL);
	return (fork);
}

t_philo	init_philo(int id, char **av)
{
	t_philo		philo;

	philo.id = id;
	philo.l_fork = init_fork(id + 1).id;
	philo.r_fork = init_fork(id).id;
	philo.right_pid = id - 1;
	philo.left_pid = id + 1;
	if (id == ft_atoi(av[1]) && id != 1)
	{
			philo.l_fork = init_fork(1).id;
			philo.left_pid = 1;
	}
	else if (ft_atoi(av[1]) == 1)
	{
		philo.left_pid = 0;
		philo.right_pid = 0;
		philo.l_fork = init_fork(0).id;
	}
	else if (id == 1 && ft_atoi(av[1]) != 1)
		philo.right_pid = ft_atoi(av[1]);
	philo.t_eat = 0;
	philo.thread = 0;
	philo.last_meal = get_timestamp();
	return (philo);
}

t_rules	*init_all(int ac, char **av)
{
	int				i;
	t_rules			*rules;

	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	rules->n = ft_atoi(av[1]);
	rules->death = ft_atoi(av[2]);
	rules->eat = ft_atoi(av[3]);
	rules->sleep = ft_atoi(av[4]);
	pthread_mutex_init(&rules->print, NULL);
	if (ac == 6)
		rules->n_eat = ft_atoi(av[5]);
	else
		rules->n_eat = 0;
	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		rules->philo[i] = init_philo(i + 1, av);
		rules->philo[i].rules = rules;
		rules->fork[i] = init_fork(i + 1);
	}
	return (rules);
}
