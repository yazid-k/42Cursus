/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:26:31 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/28 17:57:30 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*remove_quotes(char *str)
{
	char	*ret;
	int		i;
	int		j;
	char	c;

	ret = malloc(ft_strlen(str) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i++];
			while (str[i] && str[i] != c)
				ret[j++] = str[i++];
		}
		else
			ret[j++] = str[i];
	}
	ret[j] = 0;
	return (ret);
}

int	skip_and_copy(char *str, char *ret, int *i, int *j)
{
	char	c;

	if (str[*i] && (str[*i] == 34 || str[*i] == 39))
	{
		c = str[(*i)++];
		while (str[*i] && str[*i] != c)
			ret[(*j)++] = str[(*i)++];
		return (1);
	}
	return (0);
}

char	*remove_spaces(char *s)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!skip_and_copy(s, ret, &i, &j))
		{
			if (s[i] == '|')
			{
				ret[j++] = s[i++];
				while (s[i] && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
					i++;
			}
			else
				ret[j++] = s[i++];
		}
	}
		ret[j] = 0;
	return (ret);
}

char	*transform_string(char *str)
{
	char	*ret;
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = remove_spaces(str);
	if (!tmp || !ft_strlen(tmp))
		return (NULL);
	ret = remove_quotes(tmp);
	free(tmp);
	if (!ret || !ft_strlen(ret))
		return (NULL);
	return (ret);
}
