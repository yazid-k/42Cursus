/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:14:56 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/06 15:56:07 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	elemclear(t_elem **elem)
{
	t_elem	*tmp;

	while (*elem)
	{
		tmp = (*elem)->next;
		free(*elem);
		*elem = tmp;
	}
}

void	elemadd_back(t_elem **lst, t_elem *new)
{
	t_elem	*l;

	if (*lst)
	{
		l = elemlast(*lst);
		if (l)
			l->next = new;
	}
}

t_elem	*elemlast(t_elem *lst)
{
	if (!lst || !lst->next)
		return (lst);
	lst = lst->next;
	return (elemlast(lst));
}

t_elem	*elemnew(void)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	return (elem);
}

int	elemsize(t_elem *lst)
{
	int		i;
	t_elem	*l;

	i = 0;
	l = lst;
	while (l != NULL)
	{
		i++;
		l = l->next;
	}
	return (i);
}
