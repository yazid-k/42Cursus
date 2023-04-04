/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:42:33 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 17:24:32 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	dup_fds(t_data *data, t_cmd *cmd_exec, int i)
{
	if (cmd_exec->fd_in != -1)
		dup2(cmd_exec->fd_in, STDIN_FILENO);
	else if (i != 0)
		dup2(data->pfd[i - 1][0], STDIN_FILENO);
	if (cmd_exec->fd_out != -1)
		dup2(cmd_exec->fd_out, STDOUT_FILENO);
	else if (i != data->nbr_pipe)
		dup2(data->pfd[i][1], STDOUT_FILENO);
}

void free_exeve(t_data *data, t_cmd *cmd_exec)
{
	(void)cmd_exec;
	//ft_free(cmd_exec->cmd_arg);
	free_pfd(data);
	//exit(127);
}

char	**ft_get_path(char  **env)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
		i++;
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}

char	*get_cmd(char *cmd, char **envp)
{

	char 	**paths;
	char	*path;
	char	*slash;
	int		i;

	paths = ft_get_path(envp);
	i = -1;
	while (paths[++i])
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash, cmd);
		free(slash);
		if (!access(path, F_OK))
		{
			ft_free(paths);
			return (path);
		}
		free(path);
	}
	ft_free(paths);
	return (NULL);
}

int	child(t_cmd *cmd_exec,t_data *data)
{
	// if(ft_strchr(cmd_exec->cmd[0],'/'))
	// {
	// 		verif(cmd_exec);
	// 		free_exeve(data,cmd_exec);
	// }
	if (is_builtin(cmd_exec->cmd_arg))
	{
		ft_built(data, cmd_exec->cmd_arg, cmd_exec);
		ft_close(data, cmd_exec);
		free_exeve(data,cmd_exec);
	}
	else if (cmd_exec->cmd_arg[0])
		search_and_execve(cmd_exec, data);
	else 
		free_exeve(data,cmd_exec);	
	return (g_exit_code);
}
	