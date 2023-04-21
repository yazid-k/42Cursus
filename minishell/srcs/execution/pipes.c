/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:04:11 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 23:24:28 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_closefile(t_cmd *tmp)
{
	while (tmp)
	{
		if (tmp->fd_out > 0)
			close(tmp->fd_out);
		if (tmp->fd_in > 0)
			close(tmp->fd_in);
		tmp = tmp->next;
	}
}

void	child_pid(t_cmd *cmd_exec, t_data *data, int *index)
{
	signal(SIGINT, &ctrlc2);
	signal(SIGQUIT, &antislash);
	data->env_cpy = pass_env_list_to_tab(data->env_lst);
	dup_fds(data, cmd_exec, *index);
	g_exit_code = execute_child(cmd_exec, data);
	free_exec(data, cmd_exec);
	ft_free((void **)&data->here);
	exit(g_exit_code);
}

void	parent_pid(t_cmd *cmd_exec, t_data *data)
{
	(void)cmd_exec;
	close(data->pfd[1]);
	if (data->prev_pipe != -1)
		close(data->prev_pipe);
	data->prev_pipe = data->pfd[0];
	signal(SIGQUIT, SIG_IGN);
}

int	pipe_func(t_data *data, t_cmd *cmd_exec, int *i)
{
	pipe(data->pfd);
	cmd_exec->pid = fork();
	if (cmd_exec->pid == -1)
		return (write(2, "Error Fork\n", 12));
	if (cmd_exec->pid == 0)
		child_pid(cmd_exec, data, i);
	else
		parent_pid(cmd_exec, data);
	(*i)++;
	return (0);
}

int	exec_pipe(t_cmd *cmd_exec, t_data *data)
{
	int		i;
	t_cmd	*tmp;
	t_cmd	*tmpfile;

	i = 0;
	tmp = cmd_exec;
	tmpfile = cmd_exec;
	data->prev_pipe = -1;
	while (cmd_exec != NULL)
	{
		if (pipe_func(data, cmd_exec, &i))
			return (1);
		cmd_exec = cmd_exec->next;
	}
	ft_closefile(tmpfile);
	ft_close_and_wait(data, tmp, i);
	if (data->nbr_cmd)
		close(data->pfd[0]);
	return (g_exit_code);
}
