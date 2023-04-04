/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:28:03 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 19:27:46 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	dup_fds_one_cmd(t_cmd *cmd_exec)
{
	if (cmd_exec->fd_in > 2)
		dup2(cmd_exec->fd_in, 0);
	if (cmd_exec->fd_out > 2)
		dup2(cmd_exec->fd_out, 1);
}

int 	execve_path(t_cmd *cmd_exec, t_data *data)
{
	if (get_cmd(cmd_exec->cmd_arg[0], data->env_cpy))
	{
		execve(get_cmd(cmd_exec->cmd_arg[0], data->env_cpy),
			cmd_exec->cmd_arg, data->env_cpy);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_exec->cmd_arg[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_free(cmd_exec->cmd_arg);
		g_exit_code = 127;
	}
	return (g_exit_code);
}

int 	search_and_execve(t_cmd *cmd_exec, t_data *data)
{
	int check_access;

	check_access = access((cmd_exec->cmd_arg[0]), X_OK);
	if (check_access == 0)
	{
		execve(cmd_exec->cmd_arg[0], cmd_exec->cmd_arg, data->env_cpy);
		//exit (127);
	}
	else if (check_access == -1)
		g_exit_code = execve_path(cmd_exec, data);
	else
		free_exeve(data,cmd_exec);
	return (g_exit_code);
}

int exec_one_cmd(t_cmd *cmd_exec, t_data *data)
{
	cmd_exec->pid_one = fork();
	if (cmd_exec->pid_one == -1)
		return (write(2, "Error Fork\n", 12), 1);
	if (cmd_exec->pid_one == 0)
	{
		dup_fds_one_cmd(cmd_exec);
		if (cmd_exec->cmd_arg[0])
			g_exit_code = search_and_execve(cmd_exec, data);
	}
	else
	{
		waitpid(cmd_exec->pid_one, 0, 0);
		ft_close_fd(cmd_exec);
	}
	return (g_exit_code);
}
