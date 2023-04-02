/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:46:58 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/01 22:54:17 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_var_len(char *str, t_env *env)
{
	char	*var;
	int		len;

	var = get_var(str, env);
	if (!var)
		return (0);
	len = ft_strlen(var);
	free(var);
	return (len);
}

int	env_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}

int	memory_needed(char *str, t_env *env, t_exp *exp)
{
	int		count;
	t_exp	*ptr;

	ptr = exp;
	count = ft_strlen(str);
	if (exp->index == -1)
		exp = exp->next;
	while (exp)
	{
		count += max(ft_strlen(exp->var) + 1, get_var_len(exp->var, env));
		exp = exp->next;
	}
	exp = ptr;
	return (count + 1);
}

void	init_func(char *s, int *i, t_exp *exp)
{
	int	start;

	start = (*i);
	(*i)++;
	if (s[(*i)] && s[(*i)] == '?')
	{
		expadd_back(&exp, expnew(ft_strdup("?"), start));
		(*i)++;
	}
	else if (s[(*i)] && env_char(s[(*i)]))
	{
		while (s[(*i)] && env_char(s[(*i)]))
			(*i)++;
		expadd_back(&exp, expnew(ft_substr(s, start + 1, (*i) - start - 1),
				start));
	}
}

t_exp	*init_expand(char *s)
{
	int			i;
	int			size;
	t_exp		*exp;
	t_exp		*ptr;

	if (!s)
		return (NULL);
	exp = expnew(NULL, -1);
	if (!exp)
		return (NULL);
	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '$')
		{
			if (s[i] && s[i] == 39)
				skip_quotes(s, &i);
			else
				i++;
		}
		if (s[i] && s[i] == '$')
			init_func(s, &i, exp);
	}
	ptr = exp->next;
	free(exp);
	exp = ptr;
	return (exp);
}
