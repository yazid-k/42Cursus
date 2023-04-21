/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:20:45 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/18 18:22:29 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_getenv(t_env *env_lst, char *str)
{
	t_env	*tmp;

	tmp = env_lst;
	while (tmp && tmp->env_str
		&& ft_strncmp(str, tmp->env_str, ft_strlen(str)) != 0)
		tmp = tmp->next;
	if (!tmp || !tmp->env_str
		|| ft_strncmp(str, tmp->env_str, ft_strlen(str)) != 0)
		return (NULL);
	return (tmp->env_str + (ft_strlen(str) + 1));
}

static void	replace_pwd(char *path, t_env *env_lst)
{
	t_env	*tmp;

	tmp = env_lst;
	while (tmp && tmp->env_str && ft_strncmp("PWD", tmp->env_str, 3) != 0)
		tmp = tmp->next;
	if (!tmp || !tmp->env_str)
		return ;
	free(tmp->env_str);
	tmp->env_str = ft_strjoin("PWD=", path);
	if (!tmp->env_str)
		return ;
}

static void	replace_oldpwd(char *path, t_env *env_lst)
{
	t_env	*tmp;

	tmp = env_lst;
	while (tmp && tmp->env_str && ft_strncmp("OLDPWD", tmp->env_str, 3) != 0)
		tmp = tmp->next;
	if (!tmp)
		lst_manager(&env_lst, tmp->env_str);
	else
		free(tmp->env_str);
	tmp->env_str = ft_strjoin("OLDPWD=", path);
	if (!tmp->env_str)
		return ;
}

int	set_home_dir(t_env *env_lst)
{
	if (!ft_getenv(env_lst, "HOME"))
	{
		ft_putendl_fd("cd: HOME not set", STDERR_FILENO);
		return (g_exit_code = 1, 1);
	}
	else if (chdir(ft_getenv(env_lst, "HOME")) == -1)
		ft_printf("error HOME\n");
	else
		replace_pwd(ft_getenv(env_lst, "HOME"), env_lst);
	return (0);
}

int	ft_cd(char **cmd, t_env *env_lst)
{
	char	*path;
	char	pwd[1024];
	char	owd[1024];

	ft_bzero(owd, 1024);
	getcwd(owd, sizeof(owd));
	path = cmd[1];
	if (!path)
		return (set_home_dir(env_lst));
	if (cmd[2])
	{
		ft_putendl_fd("cd: too many arguments", STDERR_FILENO);
		return (g_exit_code = 1);
	}
	if (chdir(path) == -1)
		return (perror(path), g_exit_code = 1);
	else
	{
		if (owd[0] == '\0')
			return (perror("get cwd"), g_exit_code = 1);
		replace_oldpwd(owd, env_lst);
		replace_pwd(getcwd(pwd, sizeof(pwd)), env_lst);
	}
	return (g_exit_code = 0);
}
