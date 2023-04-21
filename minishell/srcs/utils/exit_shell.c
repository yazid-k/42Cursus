/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:27:03 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 22:22:08 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_all_before_exit(t_data *data, t_cmd *cmd)
{
	if (cmd)
		cmdclear(cmd);
	if (data)
	{
		if (data->env_lst)
			free_lst(&data->env_lst);
	}
	if (data->env_cpy)
		free_tab((void **)data->env_cpy);
	if (data->fd > 0)
		close(data->fd);
	if (data->fd > 0)
		close(data->fd_out);
	if (data->fd > 0)
		close(data->fd_in);
}

void	exit_shell(t_data *data, t_cmd *cmd, int code)
{
	rl_clear_history();
	if (data)
		free_all_before_exit(data, cmd);
	exit(code);
}
