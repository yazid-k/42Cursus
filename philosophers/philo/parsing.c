/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:26:22 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/08 13:27:34 by ekadiri          ###   ########.fr       */
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
	if (ac == 6)
	{
		if (!is_number(av[5]))
			return (printf("Numeric arguments needed\n"), 0);
	}
	if (ft_atoi(av[1]) < 1)
		return (printf("At least one philosophers needed\n"), 0);
	if (ft_atoi(av[2]) < 1 || ft_atoi(av[3]) < 1 || ft_atoi(av[4]) < 1)
		return (printf("Invalid time entered\n"), 0);
	if (ft_atoi(av[1]) > 1024)
		return (printf("Max philosophers reached\n"), 0);
	return (1);
}
