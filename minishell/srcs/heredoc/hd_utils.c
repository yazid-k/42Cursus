/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:48:18 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/11 04:40:10 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	func(t_data *data, t_cmd *cmd, int *nb)
{
	data->here[*nb].delim = cmd->token->content;
	pipe(data->here[(*nb)++].pipe);
}

void	get_delims_str(t_cmd *cmd, t_data *data)
{
	int	nb;

	nb = 0;
	while (cmd)
	{
		while (cmd->token)
		{
			if (cmd->token->type == A_DLESS)
				func(data, cmd, &nb);
			if (cmd->token->next)
				cmd->token = cmd->token->next;
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
			return ;
		}
	}
}

int	ft_count_hd(t_cmd *cmd)
{
	int	count;

	count = 0;
	while (cmd)
	{
		while (cmd->token)
		{
			if (cmd->token->type == A_DLESS)
				count++;
			if (cmd->token->next)
				cmd->token = cmd->token->next;
			else
			{
				cmd->token = tokenfirst(cmd->token);
				break ;
			}
		}
		if (cmd->next)
			cmd = cmd->next;
		else
			return (cmd = cmdfirst(cmd), count);
	}
	return (count);
}
