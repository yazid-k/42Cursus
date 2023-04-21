/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_for_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:03:01 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/11 04:53:05 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_lstsize_marine(t_env *env_lst)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env_lst;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	*p(t_env **env_lst, t_env **tmp, char ***env_tab)
{
	if (!*env_lst)
		return (NULL);
	*tmp = *env_lst;
	*env_tab = NULL;
	*env_tab = malloc(sizeof(char *) * (ft_lstsize_marine(*env_lst) + 1));
	if (!*env_tab)
		return (NULL);
	return (env_tab);
}

char	**pass_env_list_to_tab(t_env *env_lst)
{
	char	**env_tab;
	t_env	*tmp;
	int		i;
	int		j;

	i = -1;
	if (!p(&env_lst, &tmp, &env_tab))
		return (NULL);
	while (tmp != NULL)
	{
		env_tab[++i] = ft_strdup(tmp->env_str);
		if (!env_tab[i])
		{
			ft_printf("Error: Memory allocation failed.\n");
			j = -1;
			while (++j < i)
				free(env_tab[j]);
			free(env_tab);
			return (NULL);
		}
		tmp = tmp->next;
	}
	env_tab[ft_lstsize_marine(env_lst)] = NULL;
	return (env_tab);
}
