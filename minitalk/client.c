/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:38:30 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/16 19:54:08 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	parse(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (0);
	i = -1;
	while (av[1][++i])
	{
		if (!ft_isdigit(av[1][i]))
			return (0);
	}
	return (1);
}

int	power(int base, int a)
{
	if (a != 0)
		return (base * power(base, a - 1));
	else
		return (1);
}

void	send_char(char c, int pid)
{
	int	i;
	int	ch;

	(void)c;
	ch = c;
	i = 6;
	while (i >= 0)
	{
		if (ch / power(2, i))
		{
			kill(pid, SIGUSR1);
			ch -= power(2, i);
		}
		else
			kill(pid, SIGUSR2);
		usleep(20);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;
	int		i;

	if (!parse(ac, av))
	{
		ft_printf("Error\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	i = -1;
	while (str[++i])
		send_char(str[i], pid);
	return (1);
}
