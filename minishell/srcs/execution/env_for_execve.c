/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_for_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:03:01 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/02 15:42:58 by mvicedo          ###   ########.fr       */
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

char **pass_env_list_to_tab(t_env *env_lst)
{
    char    **env_tab;
    int     tab_size;
    t_env   *tmp;
    int     i;

	i = -1;
	if (!env_lst)
        return (NULL);
    tmp = env_lst;
    env_tab = NULL;
    tab_size = ft_lstsize_marine(env_lst);
    env_tab = malloc(sizeof(char *) * (tab_size + 1));
    if (!env_tab)
        return (NULL);
    while (tmp != NULL)
    {
        env_tab[++i] = ft_strdup(tmp->env_str);
        if (!env_tab[i])
        {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            for (int j = 0; j < i; ++j)
                free(env_tab[j]);
            free(env_tab);
            return (NULL);
        }
        tmp = tmp->next;
    }
    env_tab[tab_size] = NULL;
    return (env_tab);
}
