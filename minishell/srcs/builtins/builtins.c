/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:41:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 13:48:15 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	nb_arg(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

 int	ft_built(t_data *data, char **cmd, t_cmd *cmd_exec)
 {
	int len;
	
	len = nb_arg(cmd_exec->cmd_arg);
	
 	if (ft_strcmp(cmd[0], "exit") == 0)
 		return (ft_exit(data, cmd, cmd_exec));//, g_exit_code);
 	if (ft_strcmp(cmd[0], "pwd") == 0 )
 		return (ft_pwd());
 	else if (ft_strcmp(cmd[0], "cd") == 0)
 		return (ft_cd(cmd, data->env_lst));
 	else if (ft_strcmp(cmd[0], "echo") == 0)
 		return (ft_echo(cmd, len));
 	else if (ft_strcmp(cmd[0], "export") == 0)
 		return (ft_export(cmd_exec, data->env_lst, len), 0);
 	else if (ft_strcmp(cmd[0], "unset") == 0)
 		return (ft_unset(cmd_exec, data->env_lst, len),0);
 	else if (ft_strcmp(cmd[0], "env") == 0 && !cmd[1])
		return (ft_env(data->env_lst, len));
	return (0);
 }
 
 int	is_builtin(char **cmd)
 {
 	if (cmd[0])
 	{
 		if (ft_strcmp(cmd[0], "cd") == 0)
 			return (1);
 		else if (ft_strcmp(cmd[0], "export") == 0)
 			return (1);
 		else if (ft_strcmp(cmd[0], "unset") == 0)
 			return (1);
 		else if (ft_strcmp(cmd[0], "exit") == 0)
 			return (1);
		else if (ft_strcmp(cmd[0], "echo") == 0)
 			return (1);
		else if (ft_strcmp(cmd[0], "pwd") == 0)
 			return (1);
		else if (ft_strcmp(cmd[0], "env") == 0)
 			return (1);
		else 
			return(0);
	}
	else 
 		return (0);
 }
