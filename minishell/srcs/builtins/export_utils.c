/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:10:00 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/02 15:44:38 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int    export_msg(char *str)
{
    printf("bash: export: '%s' : not a valid identifier\n", str);
    return (0);
}


int ft_check_input(char *str)
{
    if (*str == '=' || *str == '+' || ft_isdigit(*str))
        return (0);
    while (*str && *str != '=')
    {
        if (!ft_isalnum(*str) && *str != '_')
        {
            // if (*str == '+' && *(str + 1) == '=')
            //     return (JOIN);
            return (0);
        }
        str++;
    }
    return (ADD);
}

int	ft_export_var(t_env *env_lst, char *str)
{
    int i_equal;

    i_equal = ft_is_equal(str);
    if (i_equal > 0)
    {
        if (ft_check_input(str) == ADD)//si pas de +
        {
            if (ft_is_new_var(env_lst, str, i_equal))
                return (ADD);
            else
                ft_update_var(env_lst, str, i_equal);
        }
        // else if (ft_check_input(str) == JOIN)//si y a un +
        //     str = ft_join_var(env_lst, str, i_equal);
    }
    return (i_equal);
}