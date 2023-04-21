/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:43:15 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 23:24:17 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	unset_msg(char *str)
{
	ft_printf("unset: '%s' : not a valid identifier\n", str);
	return (1);
}

int	check_unset_input(char *str)
{
	if (ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (0);
		str++;
	}
	return (1);
}

void	clear_var(t_env **env_list, char *str)
{
	t_env	*current;
	t_env	*prev;
	int		len;

	len = ft_strlen(str);
	current = *env_list;
	prev = NULL;
	while (current)
	{
		if (!ft_strncmp(current->env_str, str, len))
		{
			if (!prev)
			{
				*env_list = current->next;
			}
			else
				prev->next = current->next;
			free(current->env_str);
			free(current);
			break ;
		}
		prev = current;
		current = current->next;
	}
}

int	ft_unset(t_cmd *cmd_exec, t_env **env_lst, int len)
{
	int	i;

	if (len == 1)
		return (0);
	else if (len > 1)
	{
		i = 1;
		while (i < len)
		{
			if (!check_unset_input(cmd_exec->cmd_arg[i]))
				return (unset_msg(cmd_exec->cmd_arg[i]));
			clear_var(env_lst, cmd_exec->cmd_arg[i]);
			i++;
		}
	}
	return (0);
}
