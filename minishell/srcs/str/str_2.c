/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:34:39 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/20 20:54:20 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	space_func(char *s, char *ret, int *i, int *j)
{
	char	c;

	if (s[(*i)] && (s[(*i)] == '|' || s[(*i)] == '>' || s[(*i)] == '<'))
	{
		c = s[(*i)];
		if (*i > 0 && s[(*i) - 1] && s[(*i) - 1] != s[(*i)])
			ret[(*j)++] = 31;
		ret[(*j)++] = s[(*i)++];
		if (s[(*i)] != c)
			ret[(*j)++] = 31;
		if (s[(*i)] && s[(*i) - 1] && s[(*i) + 1] && s[(*i) - 1] == s[(*i) + 1]
			&& s[(*i)] == c)
			ret[(*j)++] = 31;
		return (1);
	}
	return (0);
}

char	*add_space(char *s)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(2 * ft_strlen(s) + spaces_to_add(s) + 15);
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == 34 || s[i] == 39)
			skip_and_copy(s, ret, &i, &j);
		if (s[i] && !space_func(s, ret, &i, &j))
			ret[j++] = s[i++];
	}
	ret[j] = 0;
	return (ret);
}

char	*new_str(char *str, t_env *env)
{
	char	*ret;
	char	*tmp;

	ret = expand(str, env);
	free(str);
	tmp = remove_spaces(ret);
	free(ret);
	ret = add_space(tmp);
	free(tmp);
	return (ret);
}
