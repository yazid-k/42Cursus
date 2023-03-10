/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_func_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:45:41 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/08 19:27:45 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	get_token_size_2(char *s)
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

int	get_token_count(char *s)
{
	int	i;

	i = 0;
	while (get_token_size_2(s))
		i++;
	return (i);
}

t_token	*create_token(char *s)
{
	static int	start = 0;
	char		*t;
	int			len;
	t_token		*token;

	if (!s)
		return (NULL);
	len = get_token_size(s);
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
	t_token	*token = NULL;
	int				i;
	int				n;
	t_token			*to_add;

	if (!s)
		return (NULL);
	if (token == NULL)
	{
		token = tokennew(NULL, START);
		if (!token)
			return (NULL);
	}
	n = get_token_count(s);
	i = -1;
	while (++i < n)
	{
		to_add = create_token(s);
		if (!to_add)
			return (tokenclear(token), NULL);
		tokenadd_back(&token, to_add);
	}
	to_add = tokennew(NULL, END);
	tokenadd_back(&token, to_add);
	return (token);
}
