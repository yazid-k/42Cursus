/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:32:47 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/21 17:51:37 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	get_env(char **cmd, char **env)
{
	int	i;

	i = 0;
	if (!cmd[1])
		return (0);
	if (!cmd[2])
	{
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	else
		printf("env: invalid option\n");
	return (0);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	char **cmd;
	int	ret;

	cmd = av;
	if (!strcmp(cmd[1], "env"))
		ret = get_env(cmd, env);
	else
		ret = -1;
	return (ret);
}


