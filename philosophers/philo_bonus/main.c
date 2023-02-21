/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:39:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/13 19:05:30 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	*rules;
	int		i;

	if (!parse(ac, av))
		return (1);
	if (ac == 6 && !ft_atoi(av[5]))
		return (0);
	rules = init_all(ac, av);
	if (!rules)
		return (1);
	i = -1;
	while (++i < ft_atoi(av[1]))
		printf("pid %d lpid %d rpid %d lfid %d rfid %d\n", rules->philo[i].id, rules->philo[i].left_pid, rules->philo[i].right_pid, rules->philo[i].left_fid, rules->philo[i].right_fid);
	free(rules);
	return (0);
}
