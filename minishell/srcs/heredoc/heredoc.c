/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:24:34 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 23:00:39 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*check_dollar(char *line, t_data *data)
{
	char	*tmp;

	if (!line)
		return (NULL);
	tmp = expand(line, data->env_lst);
	free(line);
	return (tmp);
}

static char	*open_heredoc(int index, t_data *data, t_here *here)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("heredoc> ");
		if (!line || !ft_strcmp(line, here[index].delim))
			break ;
		line = check_dollar(line, data);
		ft_putendl_fd(line, here[index].pipe[1]);
		free(line);
	}
	close(here[index].pipe[1]);
	close(here[index].pipe[0]);
	return (NULL);
}

static void	exit_hd(int sig)
{
	int		i;
	t_data	*data;

	data = starton();
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 2);
		i = -1;
		while (++i < data->nbr_here)
		{
			close(data->here[i].pipe[1]);
			close(data->here[i].pipe[0]);
		}
		ft_free((void **)&data->here);
		cmdclear(data->cmd);
		free_lst(&data->env_lst);
		g_exit_code = 130;
		exit(130);
	}
}

static void	child_hd(t_cmd *cmd, t_data *data)
{
	int	i;

	signal(SIGINT, &exit_hd);
	i = -1;
	while (++i < data->nbr_here)
		open_heredoc(i, data, data->here);
	cmdclear(cmd);
	free_lst(&data->env_lst);
	ft_free((void **)&data->here);
	exit(1);
}

void	handle_heredoc(t_cmd *cmd, t_data *data)
{
	int		i;
	pid_t	pid;

	i = -1;
	data->nbr_here = ft_count_hd(cmd);
	if (!data->nbr_here)
		return ;
	data->here = ft_calloc(sizeof(t_here), data->nbr_here);
	get_delims_str(cmd, data);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	i = -1;
	if (pid == 0)
		child_hd(cmd, data);
	else
	{
		while (++i < data->nbr_here)
			close(data->here[i].pipe[1]);
	}
	signal(SIGINT, &ctrlc2);
	waitpid(pid, NULL, 0);
	return ;
}
