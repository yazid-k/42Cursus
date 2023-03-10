/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_func_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:35:43 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/02 17:00:16 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	tokenadd_back(t_token **lst, t_token *new)
{
	t_token	*l;

	if (*lst)
	{
		l = tokenlast(*lst);
		if (l)
		{
			l->next = new;
			l->next->prev = l;
		}
	}
}

void	tokenadd_front(t_token **lst, t_token *new)
{
	new->next = *lst;
	*lst = new;
}

int	tokensize(t_token *lst)
{
	int		i;
	t_token	*l;

	i = 0;
	l = lst;
	while (l != NULL)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_token	*tokennew(char *content, t_type type)
{
	t_token	*list;

	list = malloc(sizeof(t_token));
	if (!list)
		return (NULL);
	list->content = content;
	list->type = type;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	tokenclear(t_token *lst)
{
	t_token	*tmp;

	lst = tokenfirst(lst);
	while (lst)
	{
		tmp = lst->next;
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = tmp;
	}
}
