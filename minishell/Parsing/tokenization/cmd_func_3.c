/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_func_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:20:29 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/28 19:14:56 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*create_token_cmd(t_token *token, int i)
{
	t_token	*ret;
	t_token	*t;
	int		start;
	int		size;

	if (!token)
		return (NULL);
	if (i > tokensize(token) - 2)
		return (NULL);
	t = token;
	if (t->type == START)
		t = t->next;
	start = -1;
	while (++start < i)
		t = t->next;
	size = 0;
	while (t->type != PIPE && t->next)
	{
		t = t->next;
		size++;
	}
	ret = sub_token(token, start, size);
	if (!ret)
		return (NULL);
	return (ret);
}

t_cmd	*create_cmd(t_token *token, int i)
{
	t_token			*st;
	t_token			*t;
	t_cmd			*cmd;
	char			*str;

	if (!token)
		return (NULL);
	st = token;
	t = create_token_cmd(st, i);
	if (!t)
		return (NULL);
	str = get_cmd_str(t);
	if (!str)
		return (NULL);
	cmd = cmdnew(str, t);
	if (!cmd)
		return (NULL);
	return (cmd);
}

t_cmd	*create_all_cmd(t_token *t)
{
	t_cmd	*cmd;
	t_cmd	*to_add;
	int		i;

	i = 0;
	cmd = create_cmd(t, i);
	i += tokensize(cmd->token) + 1;
	to_add = create_cmd(t, i);
	if (!to_add)
		return (cmd);
	i += tokensize(to_add->token) + 1;
	while (to_add)
	{
		cmdadd_back(&cmd, to_add);
		to_add = create_cmd(t, i);
		if (!to_add)
			return (cmd);
		i += tokensize(to_add->token) + 1;
	}
	return (cmd);
}
