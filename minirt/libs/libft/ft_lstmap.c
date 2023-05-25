/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:59:47 by ekadiri           #+#    #+#             */
/*   Updated: 2022/11/13 20:02:50 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*start;

	if (!lst)
		return (NULL);
	l = ft_lstnew(f(lst->content));
	if (!l)
		return (NULL);
	start = l;
	lst = lst->next;
	while (lst)
	{
		l->next = ft_lstnew(f(lst->content));
		l = l->next;
		if (!l)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (start);
}
