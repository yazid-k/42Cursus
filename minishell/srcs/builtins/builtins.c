/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:41:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 23:25:43 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	nb_arg(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

int	ft_built(t_data *data, char **cmd, t_cmd *cmd_exec)
{
	int	len;

	len = nb_arg(cmd_exec->cmd_arg);
	if (ft_strcmp(cmd[0], "exit") == 0)
		return (ft_exit(data, cmd, cmd_exec), g_exit_code);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (ft_pwd(), 0);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_cd(cmd, data->env_lst));
	else if (ft_strcmp(cmd[0], "echo") == 0)
		return (ft_echo(cmd, len), 0);
	else if (ft_strcmp(cmd[0], "export") == 0)
		return (ft_export(cmd_exec, data->env_lst, len));
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (ft_unset(cmd_exec, &data->env_lst, len));
	else if (ft_strcmp(cmd[0], "env") == 0 && !cmd[1])
		return (ft_env(data->env_lst, len));
	return (127);
}

int	is_builtin(char **cmd)
{
	static char	*builtins[7] = {
		"cd", "export", "unset", "exit", "echo", "pwd", "env"};
	int			i;

	i = -1;
	while (++i < 7)
	{
		if (cmd[0] && !ft_strcmp(cmd[0], builtins[i]))
			return (1);
	}
	return (0);
}
