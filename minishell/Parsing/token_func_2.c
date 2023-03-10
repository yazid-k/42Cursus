/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_func_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:37:29 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/27 16:34:12 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	get_token_size(char *s)
{
	static int	i = 0;
	int			start;
	int			sep;

	if (i > (int)ft_strlen(s))
	{
		i = 0;
		return (0);
	}
	start = i;
	sep = sep_size(s, &i);
	if (sep)
		return (sep);
	while (s[i] && s[i] != '>' && s[i] != '<' && s[i] != '|')
	{
		skip_quotes(s, &i);
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
			return (i - start);
		i++;
	}
	return (i - start);
}
