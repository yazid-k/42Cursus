/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:42:33 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 23:57:36 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	dupnclose(int fd, int fd2)
{
	dup2(fd, fd2);
	close(fd);
}

void	dup_fds(t_data *data, t_cmd *cmd_exec, int i)
{
	if (i != 0)
		dupnclose(data->prev_pipe, STDIN_FILENO);
	if (i != data->nbr_pipe)
		dup2(data->pfd[1], STDOUT_FILENO);
	ft_close(data, cmd_exec);
	openfiles(cmd_exec, data);
}

void	redir_fd(int *fd, t_cmd *tmp, t_data *data)
{
	if (tmp->token->type == 8 || tmp->token->type == 9)
	{
		data->fd_out = dup(*fd);
		close(*fd);
		dupnclose(data->fd_out, STDOUT_FILENO);
	}
	if (!is_builtin(tmp->cmd_arg) && (tmp->token->type == A_LESS
			|| tmp->token->type == A_DLESS))
	{
		data->fd_in = dup(*fd);
		close(*fd);
		dupnclose(data->fd_in, STDIN_FILENO);
	}
}

void	openfiles_continue(t_cmd *cmd, t_cmd *tmp, t_data *data)
{
	int	fd;

	fd = -1;
	if (tmp->token->type == 8)
		fd = open(tmp->token->content, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (tmp->token->type == 9)
		fd = open(tmp->token->content, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (tmp->token->type == A_LESS)
	{
		fd = open(tmp->token->content, O_RDONLY);
		if (is_builtin(tmp->cmd_arg))
			if (fd > 0)
				close(fd);
	}
	if (tmp->token->type == A_DLESS)
		fd = heredoc_pipe(data->here, data, tmp->token->content);
	if ((fd == -1) && (tmp->token->type == 8 || tmp->token->type == 9
			|| tmp->token->type == A_LESS))
		error_fd(tmp->token, cmd, data);
	redir_fd(&fd, tmp, data);
}

void	openfiles(t_cmd *cmd, t_data *data)
{
	t_cmd	*tmp;
	t_token	*t;

	tmp = cmd;
	t = tmp->token;
	while (tmp->token)
	{
		openfiles_continue(cmd, tmp, data);
		tmp->token = tmp->token->next;
	}
	tmp->token = t;
}
