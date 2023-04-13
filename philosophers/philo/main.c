/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:39:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/13 11:34:00 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	func(char **av)
{
	printf("0 1 has taken a fork\n");
	usleep(1000 * ft_atoi(av[2]));
	printf("%d 1 died\n", ft_atoi(av[2]));
}

int	main(int ac, char **av)
{
	t_rules	*rules;

	if (!parse(ac, av))
		return (1);
	if (ac == 6 && !ft_atoi(av[5]))
		return (0);
	if (ft_atoi(av[1]) == 1)
	{
		func(av);
		return (0);
	}
	rules = init_all(ac, av);
	if (!rules)
		return (1);
	start(rules);
	return (0);
}
