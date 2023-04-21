/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:09:51 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/11 03:28:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	var_name_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	ft_is_new_var(t_env *env_lst, char *str, int i_equal)
{
	t_env	*ptr;
	int		len;

	ptr = env_lst;
	while (ptr)
	{
		len = ft_is_equal(ptr->env_str);
		if (!ft_strncmp(ptr->env_str, str, i_equal) && len == i_equal)
			return (0);
		ptr = (ptr)->next;
	}
	return (1);
}

void	ft_update_var(t_env *env_lst, char *str, int i_equal)
{
	t_env	*ptr;
	int		len;

	ptr = env_lst;
	while (ptr)
	{
		len = ft_is_equal(ptr->env_str);
		if (!ft_strncmp(ptr->env_str, str, i_equal) && len == i_equal)
		{
			free(ptr->env_str);
			ptr->env_str = ft_strdup(str);
		}
		ptr = ptr->next;
	}
}
