/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:13:21 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/16 19:50:08 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int base, int a)
{
	if (a != 0)
		return (base * power(base, a - 1));
	else
		return (1);
}

void	convert_char(int s)
{
	static int	bits = 0;
	static int	ascii = 0;

	if (s == SIGUSR1 || s == SIGUSR2)
	{
		if (s == SIGUSR1)
			ascii += power(2, 6 - bits);
		bits++;
	}
	if (bits == 7)
	{
		write(1, &ascii, 1);
		ascii = 0;
		bits = 0;
	}
}

int	main(int ac, char **av)
{
	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, convert_char);
		signal(SIGUSR2, convert_char);
	}
	(void)ac;
	(void)av;
	return (0);
}
