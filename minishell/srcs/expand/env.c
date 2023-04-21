/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:02:26 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/17 19:00:45 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lst_manager(t_env **env_lst, char *env_str)
{
	t_env	*node;
	t_env	*tail;

	node = malloc(sizeof(t_env));
	if (!node)
		return ;
	node->env_str = ft_strdup(env_str);
	if (!node->env_str)
		return ;
	node->next = NULL;
	if (*env_lst == NULL)
		*env_lst = node;
	else
	{
		tail = *env_lst;
		while (tail->next)
			tail = tail->next;
		tail->next = node;
	}
}

void	free_lst(t_env **env_lst)
{
	t_env	*temp;

	if (!env_lst || !(*env_lst))
		return ;
	while (*env_lst)
	{
		free((*env_lst)->env_str);
		temp = (*env_lst)->next;
		free(*env_lst);
		*env_lst = temp;
	}
	*env_lst = NULL;
}

t_env	*ft_init_env(char **env)
{
	t_env	*env_lst;

	env_lst = NULL;
	while (*env)
	{
		lst_manager(&env_lst, *env);
		env++;
	}
	return (env_lst);
}
