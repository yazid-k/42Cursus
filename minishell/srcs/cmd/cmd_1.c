/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:49:46 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/04 16:56:50 by mvicedo          ###   ########.fr       */
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
		free_tab((void **)lst->cmd_arg);
		if (lst->cmd_path)
			free(lst->cmd_path);
		free(lst);
		lst = tmp;
	}
}
