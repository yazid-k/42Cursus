/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_func_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:20:29 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/08 20:41:42 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*create_token_cmd(t_token *token)
{
	static int		i = 0;
	static t_token	*t = NULL;
	t_token			*ret;
	int				start;

	start = i;
	if (!token)
		return (NULL);
	if (!t)
		t = token;
	while (t->type != PIPE && t->next)
	{
		t = t->next;
		i++;
	}
	t = t->next;
	if (!start)
		ret = sub_token(tokenfirst(token), start, i - start - 1);
	else
		ret = sub_token(tokenfirst(token), start, i++ - start);
	if (!ret)
		return (NULL);
	return (ret);
}

t_cmd	*create_cmd(t_token *token)
{
	t_token			*st;
	t_token			*t;
	t_cmd			*cmd;
	char			*str;

	if (!token)
		return (NULL);
	st = token;
	t = create_token_cmd(st);
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

	cmd = create_cmd(t);
	to_add = create_cmd(t);
	while (to_add)
	{
		cmdadd_back(&cmd, to_add);
		to_add = create_cmd(t);
	}
	return (cmd);
}
