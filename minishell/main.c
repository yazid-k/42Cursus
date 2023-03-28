/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:34:30 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/28 18:54:06 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(char *str)
{
/* 	t_token	*t;
	t_cmd	*cmd;
	char	*input;


	if (!closed_quotes(str))
		return (printf("bash : syntax error unterminated quoted string\n"), 0);
	input = transform_string(str);
	if (!input)
		return (0);
	t = init_tokens(input);
	cmd = create_all_cmd(t);
	//print_cmd(cmd);
	if (parse(cmd))
	{
		cmdclear(cmd);
		tokenclear(t);
		free(input);
		return (1);
	}
	free(input);
	cmdclear(cmd);
	tokenclear(t);
	return (0); */
	return (printf("n expand %d\n", count_expands(str)));
}

int	main(int ac, char **av)
{
	char	*str;

	(void)ac;
	(void)av;
	while (1)
	{
		str = readline("ekadiri> ");
		add_history(str);
		if (!str)
			break ;
		if (!ft_strncmp("exit", str, 5))
			return (free(str), 0);
		if (!*str)
			continue ;
		if (minishell(str))
			printf("Parsed\n");
		free(str);
	}
}
/*
int	main(int ac, char **av, char **env)
{
	t_env	*e;
	char	*s;

	e = ft_init_env(env);
	s = get_var(av[ac - 1], e);
	printf("%s\n", s);
	if (s)
		free(s);
	free_lst(&e);
	return (0);
}
 */
