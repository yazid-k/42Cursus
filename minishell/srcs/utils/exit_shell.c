/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:27:03 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 19:26:28 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_ptr(void *thing)
{
	if (thing)
	{
		free(thing);
		thing = NULL;
	}
}

void	free_all_before_exit(t_data *data, t_cmd *cmd)
{
	if (cmd)
		cmdclear(cmd);
	if (data)
	{
		if (data->env_cpy[0])
			free_tab((void **)data->env_cpy);
		if (data->env_lst)
			free_lst(&data->env_lst);
	}
	free(data->pfd);
}

void	exit_shell(t_data *data, t_cmd *cmd, int code)
{
	clear_history();
	if (data)
		free_all_before_exit(data, cmd);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit(code);
}
