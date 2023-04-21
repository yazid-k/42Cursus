/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:17:05 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/11 03:47:30 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_struct(t_data *data, char **env)
{
	t_here	here;

	data->here = &here;
	data->nbr_cmd = 0;
	data->nbr_pipe = 0;
	data->env_cpy = NULL;
	data->env_lst = ft_init_env(env);
}
