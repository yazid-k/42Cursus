/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:17:05 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 16:45:40 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int    init_struct(t_data *data, char **env)
{
    //data->exit_status = 0;
    data->nbr_cmd = 0;
    data->nbr_pipe = 0;
    data->env_cpy = NULL;
    data->env_lst = ft_init_env(env);
    if (data->env_lst == NULL)
    {
        printf("error : initialization of environment");
        return (0);
    }
    return(1);
}