/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:34:30 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/15 16:37:37 by ekadiri          ###   ########.fr       */
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
	char	*s;

	if (!closed_quotes(str))
		return (ft_printf("quote error\n"), 0);
	s = new_str(str, env);
	data->t = init_tokens(s);
	free(s);
	data->cmd = create_all_cmd(data->t);
	tokenclear(data->t);
	if (!parse(data->cmd))
		return (cmdclear(data->cmd), 1);
	g_exit_code = exec_cmd(data->cmd, data);
	return (cmdclear(data->cmd), 0);
}

t_data	*starton(void)
{
	static t_data	data;

	return (&data);
}

int	abcdefg(char *s)
{
	while (*s)
	{
		if (!(*s == 32 || (*s >= 9 && *s <= 13)))
			return (0);
		s++;
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_data	*data;

	(void)ac;
	(void)av;
	data = starton();
	signal(SIGQUIT, SIG_IGN);
	init_struct(data, env);
	while (1)
	{
		signal(SIGINT, &ctrlc);
		str = readline("minishell> ");
		if (!str)
			break ;
		if (!*str || abcdefg(str))
			continue ;
		add_history(str);
		if (minishell(str, data->env_lst, data))
			continue ;
	}
	free_lst(&data->env_lst);
	free_tab((void **)data->env_cpy);
	rl_clear_history();
	printf("exit\n");
	return (exit(g_exit_code), 0);
}
