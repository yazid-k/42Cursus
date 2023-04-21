/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:30:41 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/15 18:41:01 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_exp	*expnew(char *content, int index)
{
	t_exp	*exp;

	exp = malloc(sizeof(t_exp));
	if (!exp)
		return (NULL);
	exp->index = index;
	exp->var = content;
	exp->next = NULL;
	return (exp);
}

t_exp	*explast(t_exp *exp)
{
	if (!exp || !exp->next)
		return (exp);
	exp = exp->next;
	return (explast(exp));
}

void	expclear(t_exp *exp)
{
	t_exp	*tmp;

	while (exp)
	{
		tmp = exp->next;
		free(exp->var);
		free(exp);
		exp = tmp;
	}
}

void	expadd_back(t_exp **lst, t_exp *new)
{
	t_exp	*l;

	if (*lst)
	{
		l = explast(*lst);
		if (l)
			l->next = new;
	}
}

char	*get_var(char *str, t_env *env)
{
	char	*s;
	int		i;
	char	*r;

	if (!str || !env)
		return (NULL);
	if (!ft_strncmp(str, "?", ft_strlen(str) + 2))
		return (ft_itoa(g_exit_code % 256));
	i = -1;
	s = malloc(ft_strlen(str) + 2);
	while (str[++i])
		s[i] = str[i];
	s[i] = '=';
	s[i + 1] = 0;
	while (env)
	{
		if (!ft_strncmp(s, env->env_str, ft_strlen(s)))
		{
			r = ft_substr(env->env_str, ft_strlen(s), ft_strlen(env->env_str));
			return (free(s), r);
		}
		env = env->next;
	}
	return (free(s), NULL);
}
