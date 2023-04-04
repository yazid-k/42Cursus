/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:02:05 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/03 22:37:22 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//env => DESKTOP_SESSION=ubuntu
//export => export DESKTOP_SESSION="ubuntu"

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

void ft_print_export(t_env **env_lst)
{
    if (!env_lst)
        return;
    t_env *ptr = *env_lst;
    t_env **head = env_lst;
    while (ptr)
	{
        printf("declare -x ");
        char *str_ptr = ptr->env_str;
        if (!ft_is_equal(str_ptr))
            while (*str_ptr != '\0')
                printf("%c", *str_ptr++);
        else
        {
            while (*str_ptr != '=')
                printf("%c", *str_ptr++);
            printf("%c", *str_ptr++);
            printf("%c", 34);
            while (*str_ptr != '\0')
                printf("%c", *str_ptr++);
            printf("%c", 34);
        }
        printf("\n");
        ptr = ptr->next;
    }
    *env_lst = *head;
}

int	ft_export(t_cmd *cmd_exec, t_env *env_lst, int len)
{
	int i;
	
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
			//lst_manager(export_lst, cmd_exec->cmd[i]);// return 0 de export var > pour toto
			i++;
		}
	}
	return (0);
}