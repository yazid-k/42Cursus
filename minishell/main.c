/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:34:30 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/05 10:17:01 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_code = 0;

void	free_all(t_cmd *cmd, t_token *token)
{
	tokenclear(token);
	cmdclear(cmd);
}

int	minishell(char *str, t_env *env, t_data *data)
{
	t_token	*t;
	t_cmd	*cmd;
	char	*s;

	printf("%d\n", g_exit_code);
	if (!closed_quotes(str))
		return (printf("bash : quote error\n"), 0);
	s = new_str(str, env);
	t = init_tokens(s);
	free(s);
	cmd = create_all_cmd(t);
	if (!parse(cmd) || !give_fd(cmd))
		return (free_all(cmd, t), 1);
	print_cmd(cmd);
	g_exit_code = exec_cmd(cmd, data);
	return (free_all(cmd, t), 0);
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	//t_env	*e;
	t_data	data;

	//e = ft_init_env(env);
	if (init_struct(&data, env) == 0)
		return(1);
	(void)ac;
	(void)av;
	while (1)
	{
		str = readline("minishell> ");
		add_history(str);
		if (!str)
			break ;
		// if (!ft_strncmp("exit ", str, 5))
		// 	return (free(str), free_lst(&data.env_lst), 0);
		if (!*str)
			continue ;
		if (minishell(str, data.env_lst, &data))
			continue ;
	}
}
/*

int	main(int ac, char **av, char **env)
{
	t_env	*e;
	char	*s;

	s = NULL;
	e = ft_init_env(env);
	if (ft_strlen(av[ac - 1]))
		s = new_str(av[ac - 1], e);
	if (s)
	{
		printf("%s %zu\n", s, ft_strlen(s));
		free(s);
	}
	free_lst(&e);
	return (0);
}
 */
