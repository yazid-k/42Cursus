/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:30:41 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/28 19:01:20 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_var(char *str, t_env *env)
{
	char	*s;
	int		i;
	char	*r;

	if (!str || !env)
		return (NULL);
	i = -1;
	s = malloc(ft_strlen(str) + 2);
	if (!s)
		return (NULL);
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

int	count_expands(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == 39)
		{
			i++;
			while (s[i] && s[i] != 39)
				i++;
		}
		else if (s[i] == '$')
		{
			count++;
			i++;
			while (s[i] && s[i] != '$')
				i++;
		}
	}
	return (count);
}
