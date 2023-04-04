/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:32:39 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 17:12:21 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../minishell.h"

void	ft_close_fd(t_cmd *cmd_exec)
{
	if (cmd_exec->fd_in > 2)
		close(cmd_exec->fd_in);
	if (cmd_exec->fd_out > 2)
		close(cmd_exec->fd_out);
}

void	ft_close(t_data *data, t_cmd *cmd_exec)
{
	int	i;

	i = 0;
	
	while (data->pfd && data->pfd[i])
	{
		if (data->pfd[i][0] > 2)
			close(data->pfd[i][0]);
		if (data->pfd[i][1] > 2)
			close(data->pfd[i][1]);
		i++;
	}
	if (cmd_exec->fd_in > 2)
		close(cmd_exec->fd_in);
	if (cmd_exec->fd_out > 2)
		close(cmd_exec->fd_out);
}

void	close_fd(t_data *data, t_cmd *cmd_exec)
{
	ft_close(data, cmd_exec);
	free_pfd(data);
	exit(127);
}
