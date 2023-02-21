/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:26:22 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/19 19:57:04 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	parse(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (printf("4 or 5 arguments needed\n"), 0);
	if (!is_number(av[1]) || !is_number(av[2])
		|| !is_number(av[3]) || !is_number(av[4]))
		return (printf("Numeric arguments needed\n"), 0);
	if (ft_atoi(av[1]) >= 200)
		return (printf("Maximum number of philosophers reached\n"), 0);
	if (ac == 6)
	{
		if (!is_number(av[5]))
			return (printf("Numeric arguments needed\n"), 0);
	}
	return (1);
}
