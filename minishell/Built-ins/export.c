/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:28:02 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/22 18:02:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//env => DESKTOP_SESSION=ubuntu
//export => declare -x DESKTOP_SESSION="ubuntu"

//pbm avec le display de LS_COLORS var (seg fault)

//version en cours : marche seulement pour export (sans args)

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	get_export(char **cmd, char **env)
{
	int		i;

	i = 0;
	if (cmd[2])
		return (-1);
	while(env[i])
	{
		printf("declare -x ");
		while (*env[i] != '=')
		{
			printf("%c", *env[i]);
			env[i]++;
		}
		printf("%c", *env[i++]);
		printf("%c", 34);
		while(*env[i])
		{
			printf("%c", *env[i]);
			env[i]++;
		}
		printf("%c", 34);
		printf("\n");
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	(void)	ac;
	char	**cmd;
	int 	ret;

	cmd = av;
	if (cmd[1])
	{
		if(!strcmp(cmd[1], "export"))
			ret = get_export(cmd, env);
		ret = -1;
	}
	return (ret);
}