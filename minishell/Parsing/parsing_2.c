/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:27:18 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/25 15:15:27 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	print_error(char *err)
{
	printf("bash: syntax error near unexpected token `%s'\n", err);
}

int	parse_pipes(t_cmd *cmd)
{
	while (cmd)
	{
		while (cmd->token)
		{
			if (cmd->token->type == PIPE || cmd->token->type == D_PIPE
				|| cmd->token->type == END)
				return (print_error("|"), 0);
			if (cmd->token->next)
				cmd->token = cmd->token->next;
			else
				break ;
		}
		cmd->token = tokenfirst(cmd->token);
		cmd = cmd->next;
	}
	return (1);
}

int	parse_redirections(t_cmd *cmd)
{
	while (cmd)
	{
		while (cmd->token)
		{
			if (token_is_redir(cmd->token))
			{
				if (!cmd->token->next)
				{
					if (!cmd->next)
						return (print_error("newline"), 0);
					else
						return (print_error("|"), 0);
				}
				else if (!err_redir(cmd->token->next))
					return (print_error(cmd->token->content), 0);
			}
			if (cmd->token->next)
				cmd->token = cmd->token->next;
			else
				break ;
		}
		cmd->token = tokenfirst(cmd->token);
		cmd = cmd->next;
	}
	return (1);
}

int	token_is_redir(t_token *token)
{
	if (token->type == GREAT || token->type == D_GREAT
		|| token->type == LESS || token->type == D_LESS)
		return (1);
	return (0);
}

int	err_redir(t_token *token)
{
	int	i;

	i = -1;
	if ((token->type == A_GREAT || token->type == A_DGREAT
			|| token->type == A_LESS || token->type == A_DLESS)
		&& ft_strlen(token->content))
		return (1);
	return (0);
	return (0);
}
