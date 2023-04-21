/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:28:03 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/19 17:30:09 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//void	execve_error(t_cmd *cmd_exec, int boolean);

char	**ft_get_path(char **env)
{
	char	**paths;
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}

char	*get_cmd(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*slash;
	int		i;

	paths = ft_get_path(envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash, cmd);
		free(slash);
		if (access(path, F_OK | X_OK) != -1)
		{
			free_tab((void **)paths);
			return (path);
		}
		free(path);
	}
	free_tab((void **)paths);
	return (NULL);
}

int	execve_path(t_cmd *cmd_exec, t_data *data)
{
	char	*path;

	path = get_cmd(cmd_exec->cmd_arg[0], data->env_cpy);
	if (path)
		execve(path, cmd_exec->cmd_arg, data->env_cpy);
	execve_error(cmd_exec, 1);
	free(path);
	return (g_exit_code);
}

int	search_and_execve(t_cmd *cmd_exec, t_data *data)
{
	if (cmd_exec->cmd_arg[0])
	{
		if (ft_strchr(cmd_exec->cmd_arg[0], '/') != NULL)
		{
			verif(cmd_exec, data);
			return (g_exit_code);
		}
		g_exit_code = execve_path(cmd_exec, data);
	}
	return (g_exit_code);
}

int	execute_child(t_cmd *cmd_exec, t_data *data)
{
	if (is_builtin(cmd_exec->cmd_arg))
		g_exit_code = ft_built(data, cmd_exec->cmd_arg, cmd_exec);
	else
		search_and_execve(cmd_exec, data);
	return (g_exit_code);
}
