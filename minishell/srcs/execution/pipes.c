/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:04:11 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 17:21:35 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int exec_pipe(t_cmd *cmd_exec, t_data *data)
{
	int 	i;
	int 	index;
	t_cmd	*tmp;

	i = 0;
	index = 0;
	tmp = cmd_exec;
	open_pipes(data); 
	while (cmd_exec != NULL)
	{
		cmd_exec->pid = fork();
		if (cmd_exec->pid == -1)
			return (write(2, "Error Fork\n", 12), 1);
		if (cmd_exec->pid == 0)
		{
			dup_fds(data, cmd_exec, index);
			ft_close(data, tmp);
			g_exit_code = child(cmd_exec, data);
		}
		index++;
		cmd_exec = cmd_exec->next;
	}
	ft_close_and_wait(data, tmp, i, index);
	return (g_exit_code);
}

void	open_pipes(t_data *data)
{
	int i;
	i = -1;
	data->pfd = (int **)malloc(sizeof(int *) * (data->nbr_cmd + 1));
	if (!data->pfd)
		msg_error(ERR_PIPE);
	data->pfd[data->nbr_cmd] = 0;
	while (++i < data->nbr_cmd)
	{
		data->pfd[i] = (int *)malloc(sizeof(int) * (2));
		if ((!data->pfd[i]) || pipe(data->pfd[i]))
		{
			ft_free_pipes(data, i);
			msg_error(ERR_PIPE);
		}
	}
}