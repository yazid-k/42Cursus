/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:39:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/19 20:52:03 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_rules *rules)
{
	int		i;
	t_philo	philo;

	i = -1;
	while (++i < rules->n)
	{
		philo = rules->philo[i];
		printf("Philo id : %d\n\tLeft philo id : %d\n\tRight philo id : %d\n\tLeft fork id : %d\n\tRight fork id : %d\n\tNumber of meals : %d\n\tLast meal timestamp : %ld\n\n", philo.id, philo.left_pid, philo.right_pid, philo.l_fork, philo.r_fork, philo.t_eat, philo.last_meal);
	}
}

int	main(int ac, char **av)
{
	t_rules	*rules;

	if (!parse(ac, av))
		return (1);
	if (ac == 6 && !ft_atoi(av[5]))
		return (0);
	rules = init_all(ac, av);
	if (!rules)
		return (1);
	start(rules);
	free_all(rules);
	return (0);
}
