/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:14:59 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/22 16:11:20 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
//#include "minishell.h"

void	ft_display(char **cmd, int i, int flag)
{
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
}

int	ft_echo(char **cmd)
{
	int flag;
	int	i;
	
	flag = 0;
	i = 2;
	if (!cmd[i])
		printf("\n");
	else
	{
		if (!strcmp(cmd[i],"-n"))
		{
			flag = 1;
			i++;
		}
		ft_display(cmd, i, flag);	
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;
	char **cmd;
	int	ret;
	
	cmd = av;
	if (cmd[1])
	{
		if (!strcmp(cmd[1], "echo"))
			ret = ft_echo(cmd);
		ret = -1;
	}
	return (ret);
}