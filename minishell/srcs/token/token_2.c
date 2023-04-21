/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:37:29 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/08 02:58:14 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*tokenlast(t_token *lst)
{
	if (!lst || !lst->next)
		return (lst);
	lst = lst->next;
	return (tokenlast(lst));
}

t_token	*tokenfirst(t_token *lst)
{
	if (!lst || !lst->prev)
		return (lst);
	lst = lst->prev;
	return (tokenfirst(lst));
}

void	print_token(t_token	*token)
{
	int	i;

	i = 1;
	while (token)
	{
		printf("Token %d :\n\tContent : %s \n\tType : %u\n\n", i++,
			token->content, token->type);
		token = token->next;
	}
}

t_type	get_type(char *s)
{
	if (ft_strlen(s) == 1)
	{
		if (!ft_strncmp(s, ">", 1))
			return (GREAT);
		if (!ft_strncmp(s, "<", 1))
			return (LESS);
		if (!ft_strncmp(s, "|", 1))
			return (PIPE);
	}
	else if (ft_strlen(s) == 2)
	{
		if (!ft_strncmp(s, ">>", 2))
			return (D_GREAT);
		if (!ft_strncmp(s, "<<", 2))
			return (D_LESS);
		if (!ft_strncmp(s, "||", 2))
			return (D_PIPE);
	}
	return (ARG);
}

t_token	*init_tokens(char *s)
{
	t_token	*token;
	char	**arr;
	int		i;

	arr = ft_split(s, 31);
	i = -1;
	if (!arr)
		return (NULL);
	i = -1;
	token = tokennew(NULL, START);
	while (arr[++i])
		tokenadd_back(&token, tokennew(ft_strdup(arr[i]), 0));
	tokenadd_back(&token, tokennew(NULL, END));
	give_types(token);
	quote(token);
	free_tab((void **)arr);
	return (token);
}
