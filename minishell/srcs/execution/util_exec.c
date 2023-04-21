/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:43:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 23:29:48 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	l(int choice, char *s, int exit)
{
	if (choice == 1)
		ft_printf("%s: command not found\n", s);
	else if (choice == 2)
		ft_printf("%s: Is a directory\n", s);
	else if (choice == 3)
		ft_printf("%s: Permission denied\n", s);
	else if (choice == 4)
		ft_printf("%s: No such file or directory\n", s);
	g_exit_code = exit;
}

void	execve_error(t_cmd *cmd_exec, int boolean)
{
	int	fd;

	if (boolean)
	{
		l(1, cmd_exec->cmd_arg[0], 127);
		return ;
	}
	fd = open(cmd_exec->cmd_arg[0], O_RDWR);
	if (fd == -1 && errno == EISDIR)
		l(2, cmd_exec->cmd_arg[0], 126);
	else if (errno == 13)
		l(3, cmd_exec->cmd_arg[0], 126);
	else
		l(4, cmd_exec->cmd_arg[0], 127);
	if (fd != -1)
		close(fd);
}

int	verif(t_cmd *cmd_exec, t_data *data)
{
	if (access(cmd_exec->cmd_arg[0], F_OK | X_OK) == 0)
		execve(cmd_exec->cmd_arg[0], cmd_exec->cmd_arg, data->env_cpy);
	execve_error(cmd_exec, 0);
	return (g_exit_code);
}
