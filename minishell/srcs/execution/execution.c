/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:44:06 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/21 00:10:54 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	error_fd_bt(t_token *token, t_cmd *cmd, t_data *data)
{
	(void)cmd;
	(void)data;
	if (errno == 13 && token->type != A_DLESS)
		ft_printf("%s: Permission denied\n", token->content);
	else if (token->type != A_DLESS)
		ft_printf("%s: No such file or directory\n", token->content);
	return (1);
}

void	exec_one_builtin(t_cmd *cmd_exec, t_data *data)
{
	data->fd = dup(STDOUT_FILENO);
	if (openfiles_bt(cmd_exec, data))
	{
		dupnclose(data->fd, STDOUT_FILENO);
		return ;
	}
	g_exit_code = ft_built(data, cmd_exec->cmd_arg, cmd_exec);
	dup2(data->fd, STDOUT_FILENO);
	close(data->fd);
}

void	ft_close_and_wait(t_data *data, t_cmd *tmp, int i)
{
	static int	var;

	i = 0;
	while (i < data->nbr_cmd)
	{
		waitpid(tmp->pid, & g_exit_code, 0);
		if (WIFEXITED(g_exit_code))
			g_exit_code = WEXITSTATUS(g_exit_code);
		else if (WIFSIGNALED(g_exit_code))
			g_exit_code = WTERMSIG(g_exit_code) + 128;
		if (g_exit_code == 131 && !var++)
			ft_putstr_fd("Quit (core dumped)\n", 2);
		tmp = tmp->next;
		i++;
	}
}

static void	data_for_exec(t_cmd *cmd_exec, t_data *data)
{
	data->prev_pipe = -1;
	data->nbr_cmd = cmdsize(cmd_exec);
	data->nbr_pipe = data->nbr_cmd - 1;
	data->here = NULL;
	data->nbr_here = -1;
}

int	exec_cmd(t_cmd *cmd_exec, t_data *data)
{
	int		i;

	data_for_exec(cmd_exec, data);
	handle_heredoc(cmd_exec, data);
	signal(SIGINT, SIG_IGN);
	if ((data->nbr_cmd == 1) && (is_builtin(cmd_exec->cmd_arg)))
		exec_one_builtin(cmd_exec, data);
	else
	g_exit_code = exec_pipe(cmd_exec, data);
	i = -1;
	while (++i < data->nbr_here)
		close(data->here[i].pipe[0]);
	free(data->here);
	signal(SIGINT, &ctrlc2);
	return (g_exit_code);
}
