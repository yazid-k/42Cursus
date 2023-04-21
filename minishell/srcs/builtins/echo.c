/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:33:36 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/19 19:31:11 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_display(char **cmd, int i, int flag)
{
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], STDOUT_FILENO);
		if (cmd[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (!flag)
		ft_putstr_fd("\n", STDOUT_FILENO);
}

static int	check_args(char *arg)
{
	int		i;
	int		n_flag;

	n_flag = 0;
	i = 0;
	if (arg[i] != '-')
		return (n_flag);
	i++;
	while (arg[i] && arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		n_flag = 1;
	return (n_flag);
}

int	ft_echo(char **cmd, int len)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1;
	if (len == 1)
		ft_putstr_fd("\n", 1);
	else if (len > 1)
	{
		while (cmd[i] && check_args(cmd[i]))
		{
			flag = 1;
			i++;
		}
		ft_display(cmd, i, flag);
	}
	return (0);
}
