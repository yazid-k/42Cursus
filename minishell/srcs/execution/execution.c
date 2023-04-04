/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:44:06 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 17:12:47 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_one_builtin(t_cmd *cmd_exec, t_data *data, int *fd)
{
	if (cmd_exec->fd_out > 1)
	{
		*fd = dup(1);
		dup2(cmd_exec->fd_out, 1);
	}
	ft_built(data, cmd_exec->cmd_arg, cmd_exec);
	if (cmd_exec->fd_out > 1)
	{
		dup2(*fd, 1);
		close(*fd);
	}
}

void	ft_close_and_wait(t_data *data, t_cmd *tmp, int i, int index)
{
	ft_close(data, tmp);
	while(i < index)
	{
		waitpid(tmp->pid, NULL, 0);
		tmp = tmp->next;
		i++;
	}
	free_pfd(data);
	free(data->env_cpy);
}

static void	data_for_exec(t_cmd *cmd_exec, t_data *data)
{
	data->nbr_cmd = cmdsize(cmd_exec);
	data->nbr_pipe = data->nbr_cmd - 1;
	data->env_cpy = pass_env_list_to_tab(data->env_lst);
}

int	exec_cmd(t_cmd *cmd_exec, t_data *data)
{
	int fd;

	fd = -1;
	data_for_exec(cmd_exec, data);
	if (data->nbr_cmd == 1)
	{
		if (is_builtin(cmd_exec->cmd_arg))
			exec_one_builtin(cmd_exec, data, &fd);
		else if(!is_builtin(cmd_exec->cmd_arg))
		{
			g_exit_code = exec_one_cmd(cmd_exec, data);
			return (g_exit_code);
		}
	}
	else if (data->nbr_cmd > 1) 
		g_exit_code = exec_pipe(cmd_exec, data);
	return (g_exit_code);
}
/*
	stat() récupère l'état du fichier pointé par path et remplit le tampon buf
    lstat()  est  identique  à stat(), sauf que dans le cas où path est un lien symbolique, il
       donne l'état du lien lui-même plutôt que celui du fichier visé.
*/
// int	verif(t_cmd *cmd_exec)
// {
// 	struct stat		st;
// 	int				stat;
// 	unsigned int	mode;
	

// 	stat = lstat(cmd_exec->cmd_arg[0], &st);
// 	mode = st.st_mode & S_IFMT;
// 	if (stat == -1)
// 		return (err_msg(cmd_exec->cmd_arg[0], "No such file or directory"), 127);
// 	if (access(cmd_exec->cmd_arg[0], X_OK) == 0 && (mode != S_IFLNK || mode != S_IFREG))
// 		return (err_msg( cmd_exec->cmd_arg[0], "Is a directory"), 126);
// 	if (access(cmd_exec->cmd_arg[0], X_OK) != 0)
// 		return (err_msg( cmd_exec->cmd_arg[0], "Permission denied"), 126);
// 	return(0);
// }


