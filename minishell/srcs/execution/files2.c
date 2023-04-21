/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:16:01 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/21 00:10:25 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	redir_fd_bt(int *fd, t_cmd *tmp, t_data *data)
{
	if (tmp->token->type == 8 || tmp->token->type == 9)
	{
		data->fd_out = dup(*fd);
		close(*fd);
		dupnclose(data->fd_out, STDOUT_FILENO);
	}
}

int	openfiles_bt2(t_cmd *tmp, t_cmd *cmd, t_data *data)
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
		close(fd);
	}
	if (tmp->token->type == A_DLESS)
		fd = heredoc_pipe(data->here, data, tmp->token->content);
	if ((fd == -1) && (tmp->token->type == 8 || tmp->token->type == 9
			|| tmp->token->type == A_LESS))
		if (error_fd_bt(tmp->token, cmd, data))
			return (1);
	redir_fd_bt(&fd, tmp, data);
	return (0);
}

int	openfiles_bt(t_cmd *cmd, t_data *data)
{
	t_cmd	*tmp;
	t_token	*t;

	tmp = cmd;
	t = tmp->token;
	while (tmp->token)
	{
		if (openfiles_bt2(tmp, cmd, data))
			return (1);
		tmp->token = tmp->token->next;
	}
	tmp->token = t;
	return (0);
}
