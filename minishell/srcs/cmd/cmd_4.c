/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_func_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:42:16 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/01 15:00:21 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	output(t_cmd *cmd)
{
	int	fd_out;

	fd_out = -1;
	if (cmd->token->type == A_GREAT)
		fd_out = open(cmd->token->content, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (cmd->token->type == A_DGREAT)
		fd_out = open(cmd->token->content, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd_out < 0)
		return (printf("fd error\n"));
	if (cmd->fd_out > 0)
		close(cmd->fd_out);
	cmd->fd_out = fd_out;
	return (0);
}

int	input(t_cmd *cmd)
{
	int	fd_in;

	fd_in = open(cmd->token->content, O_RDONLY);
	if (fd_in < 0)
		return (printf("bash : %s: No such file or directory\n",
				cmd->token->content));
	cmd->fd_in = fd_in;
	return (0);
}

/* void	here_doc(t_cmd *cmd)
{
	(void)cmd;
	return ;
} */

int	give_fd(t_cmd *cmd)
{
	while (cmd)
	{
		while (cmd->token)
		{
			if ((cmd->token->type == 8 || cmd->token->type == 9) && output(cmd))
				return (0);
			else if (cmd->token->type == A_LESS && input(cmd))
				return (0);
			if (cmd->token->next)
				cmd->token = cmd->token->next ;
			else
			{
				cmd->token = tokenfirst(cmd->token);
				break ;
			}
		}
		if (cmd->next)
				cmd = cmd->next ;
		else
		{
			cmd = cmdfirst(cmd);
			return (1);
		}
	}
	return (1);
}
