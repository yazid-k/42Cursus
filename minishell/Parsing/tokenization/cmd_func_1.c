/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_func_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:49:46 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/28 19:14:19 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cmdadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*l;

	if (*lst)
	{
		l = cmdlast(*lst);
		if (l)
		{
			l->next = new;
			l->next->prev = l;
		}
	}
}

void	cmdadd_front(t_cmd **lst, t_cmd *new)
{
	new->next = *lst;
	*lst = new;
}

int	cmdsize(t_cmd *lst)
{
	int		i;
	t_cmd	*l;

	i = 0;
	l = lst;
	while (l != NULL)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_cmd	*cmdnew(char *content, t_token *token)
{
	t_cmd	*list;

	list = malloc(sizeof(t_cmd));
	if (!list)
		return (NULL);
	list->cmd = content;
	list->next = NULL;
	list->prev = NULL;
	list->token = token;
	list->fd_in = -1;
	list->fd_out = -1;
	return (list);
}

void	cmdclear(t_cmd *lst)
{
	t_cmd	*tmp;

	lst = cmdfirst(lst);
	while (lst)
	{
		tmp = lst->next;
		free(lst->cmd);
		tokenclear(lst->token);
		free(lst);
		lst = tmp;
	}
}
