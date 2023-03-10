/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_func_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:48:20 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/02 16:58:40 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	type_is_sep(t_type type)
{
	if (type == PIPE || type == D_PIPE || type == D_GREAT
		|| type == D_LESS || type == GREAT || type == LESS)
		return (1);
	return (0);
}

void	give_types(t_token *t)
{
	while (t->next)
	{
		if (t->content)
			t->type = get_type(t->content);
		t = t->next;
	}
	t = tokenfirst(t);
	while (t->next)
	{
		if (!type_is_sep(t->next->type) && t->next->type != END)
		{
			if (t->type == GREAT)
				t->next->type = A_GREAT;
			else if (t->type == LESS)
				t->next->type = A_LESS;
			else if (t->type == D_GREAT)
				t->next->type = A_DGREAT;
			else if (t->type == D_LESS)
				t->next->type = A_DLESS;
		}
		t = t->next;
	}
}

void	trim_tokens(t_token *token)
{
	char	*tmp;

	while (token->next)
	{
		if (token->content)
		{
			tmp = ft_strtrim(token->content, " \t\r\n\v\f");
			if (!tmp)
				return (tokenclear(token));
			free(token->content);
			token->content = tmp;
		}
		token = token->next;
	}
}

t_token	*init_tokens(char *s)
{
	t_token	*token;

	token = create_all_tokens(s);
	if (!token)
		return (NULL);
	trim_tokens(token);
	give_types(token);
	return (token);
}
