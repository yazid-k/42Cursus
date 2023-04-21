/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:02:05 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 23:24:12 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

void	ft_print_export(t_env **env_lst)
{
	t_env	*ptr;
	t_env	**head;
	char	*str_ptr;

	ptr = *env_lst;
	head = env_lst;
	if (env_lst == NULL || *env_lst == NULL)
		return ;
	while (ptr)
	{
		printf("declare -x ");
		str_ptr = ptr->env_str;
		while (*str_ptr != '\0' && !ft_is_equal(str_ptr))
			printf("%c", *str_ptr++);
		while (*str_ptr != '=')
			printf("%c", *str_ptr++);
		printf("%c%c", *str_ptr++, 34);
		while (*str_ptr != '\0')
			printf("%c", *str_ptr++);
		printf("%c\n", 34);
		ptr = ptr->next;
	}
	*env_lst = *head;
}

int	ft_export(t_cmd *cmd_exec, t_env *env_lst, int len)
{
	int	i;

	if (len == 1)
		ft_print_export(&env_lst);
	else if (len > 1)
	{
		i = 1;
		while (i < len)
		{
			if (!ft_check_input(cmd_exec->cmd_arg[i]))
				return (export_msg(cmd_exec->cmd_arg[i]));
			if (ft_export_var(env_lst, cmd_exec->cmd_arg[i]) == ADD)
				lst_manager(&env_lst, cmd_exec->cmd_arg[i]);
			i++;
		}
	}
	return (0);
}
