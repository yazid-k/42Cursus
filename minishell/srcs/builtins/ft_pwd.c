/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:34:14 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/12 16:54:51 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(void)
{
	char	cwd[1024];

	if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("pwd: error");
		return (1);
	}
	else
	{
		printf("%s\n", cwd);
	}
	return (0);
}

void	exit_f(char **cmd)
{
	g_exit_code = 2;
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(cmd[1], STDERR_FILENO);
	ft_putendl_fd("numeric argument required", STDERR_FILENO);
}

int	ft_exit(t_data *data, char **cmd, t_cmd *cmd_exec)
{
	int	flag;
	int	ret;

	flag = 0;
	ret = 0;
	if (data->nbr_cmd == 1)
		ft_putendl_fd("exit", STDOUT_FILENO);
	if (cmd[1])
	{
		ret = get_format_code(cmd[1], &flag);
		if (flag)
			exit_f(cmd);
		else if (cmd[2])
		{
			g_exit_code = 1;
			return (ft_putendl_fd("exit: too many arguments",
					STDERR_FILENO), 1);
		}
		else
			g_exit_code = ret;
	}
	exit_free(data, cmd_exec, g_exit_code);
	return (0);
}
