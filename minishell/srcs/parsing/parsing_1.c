/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:21:41 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/09 03:07:41 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_tab(void **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	free(tab);
}

int	skip_quotes(char const *s, int *i)
{
	char	c;

	if (s[*i] == 34 || s[*i] == 39)
	{
		c = s[(*i)++];
		while (s[*i] && s[*i] != c)
			(*i)++;
		return (1);
	}
	return (0);
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
			while (s[i] && s[i] != c)
				i++;
			if (s[i] == c)
				closed = 1;
			else if (!s[i])
				return (closed);
		}
	}
	return (closed);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
