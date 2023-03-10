/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:21:41 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/26 16:49:59 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tab(void **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	skip_quotes(char *s, int *i)
{
	char	c;

	if (s[*i] == 34 || s[*i] == 39)
	{
		c = s[(*i)++];
		while (s[*i] && s[*i] != c)
			(*i)++;
	}
}

int	is_cmd(char *cmd)
{
	char		**env;
	int			i;
	char		*tmp;
	char		*n_cmd;
	struct stat	s;

	if (!ft_strlen(cmd))
		return (1);
	env = ft_split(getenv("PATH"), ':');
	i = -1;
	tmp = ft_strjoin("/", cmd);
	while (env[++i])
	{
		n_cmd = ft_strjoin(env[i], tmp);
		printf("%s\n", n_cmd);
		if (!stat(n_cmd, &s))
		{
			if (S_ISREG(s.st_mode))
				return (free(tmp), free(n_cmd), free_tab((void **)env), 0);
		}
		free(n_cmd);
	}
	return (free(tmp), free_tab((void **)env), 1);
}

int	closed_quotes(char *s)
{
	int		i;
	int		closed;
	char	c;

	closed = 1;
	i = -1;
	while (s[++i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			c = s[i];
			closed = 0;
			i++;
			while (s[i] != c && s[i])
				i++;
			if (s[i] == c)
				closed = 1;
		}
		else
			i++;
	}
	return (closed);
}

int	count_pipe(char *s)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[++i])
	{
		skip_quotes(s, &i);
		if (s[i] == '|')
			count++;
	}
	return (count);
}
