/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_func_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:45:41 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/15 15:35:41 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	sep_size(char *s, int *i)
{
	if (s[*i] == '>' || s[*i] == '<' || s[*i] == '|')
	{
		if (s[(*i) + 1] && s[*i] == s[(*i) + 1])
		{
			(*i) += 2;
			return (2);
		}
		else
		{
			(*i)++;
			return (1);
		}
	}
	return (0);
}

int	get_token_count(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = get_token_size(s, 0);
	while (i < (int)ft_strlen(s))
	{
		count++;
		i += get_token_size(s, i);
	}
	return (count + 1);
}

t_token	*create_token(char *s, int start)
{
	char		*t;
	int			len;
	t_token		*token;

	if (!s)
		return (NULL);
	len = get_token_size(s, start);
	if (!len)
		return (NULL);
	t = ft_substr(s, start, len);
	if (!t)
		return (NULL);
	token = tokennew(t, NONE);
	if (!token)
		return (NULL);
	start += len;
	return (token);
}

t_token	*create_all_tokens(char *s)
{
	t_token			*token;
	int				i;
	int				n;
	t_token			*to_add;
	int				start;

	if (!s)
		return (NULL);
	token = tokennew(NULL, START);
	if (!token)
		return (NULL);
	n = get_token_count(s);
	i = -1;
	start = 0;
	while (++i < n)
	{
		to_add = create_token(s, start);
		start += get_token_size(s, start);
		if (!to_add)
			return (tokenclear(token), NULL);
		tokenadd_back(&token, to_add);
	}
	to_add = tokennew(NULL, END);
	tokenadd_back(&token, to_add);
	return (token);
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
