/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:34:33 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/13 19:25:48 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

t_philo	init_philo(int id, char **av)
{
	t_philo	philo;

	philo.id = id;
	philo.left_fid = id + 1;
	philo.right_fid = id;
	philo.right_pid = id - 1;
	philo.left_pid = id + 1;
	if (id == ft_atoi(av[1]))
	{
		if (id == 1)
		{
			philo.left_pid = 0;
			philo.right_pid = 0;
			philo.left_fid = 0;
		}
		else
		{
			philo.left_fid = 1;
			philo.left_pid = 1;
		}
	}
	if (id == 1 && ft_atoi(av[1]) != 1)
		philo.right_pid = ft_atoi(av[1]);
	philo.t_eat = 0;
	return (philo);
}

t_rules	*init_all(int ac, char **av)
{
	int		i;
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	rules->death = ft_atoi(av[2]);
	rules->eat = ft_atoi(av[3]);
	rules->sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules->n_eat = ft_atoi(av[5]);
	else
		rules->n_eat = -1;
	i = -1;
	while (++i < ft_atoi(av[1]))
		rules->philo[i] = init_philo(i + 1, av);
	return (rules);
}
