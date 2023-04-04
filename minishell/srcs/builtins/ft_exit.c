/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:25:34 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 17:29:04 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}


static int	check_ints(int neg, unsigned long long num, int *flag)
{
	if ((neg == 1 && num > LONG_MAX)
		|| (neg == -1 && num > -(unsigned long)LONG_MIN))
		*flag = 1;
	return (*flag);
}

static int	ft_atoi_long(const char *str, int *flag)
{
	unsigned long long	num;
	int					neg;
	int					i;

	num = 0;
	neg = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (check_ints(neg, num, flag))
			break ;
		i++;
	}
	return (num * neg);
}

static int	get_format_code(char *arg, int *flag)
{
	unsigned long long	i;

	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	if (arg[i] == '\0')
		*flag = 1;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!ft_isdigit(arg[i]))
		*flag = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && !ft_isspace(arg[i]))
			*flag = 1;
		i++;
	}
	i = ft_atoi_long(arg, flag);
	return (i % 256);
}

static void	exit_free(t_data *data, t_cmd *cmd, int ret)
{
	if (cmd->fd_out != -1)
		close(cmd->fd_out);
	g_exit_code = ret;
	if (data->nbr_pipe != 0)
	{
		ft_free_pipes(data, data->nbr_cmd);
		exit_shell(data, cmd, g_exit_code);
	}
	exit_shell(data, cmd, g_exit_code);
}


int	ft_exit(t_data *data, char **cmd, t_cmd *cmd_exec)
{
	int	flag;
	int ret;

	flag = 0;
	ret = 0;
	if (data->nbr_cmd == 1)
		ft_putendl_fd("exit", STDOUT_FILENO);
	if (cmd[1])
	{
		ret = get_format_code(cmd[1], &flag);
		if (flag)
		{
			ret = 2;
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(cmd[1], STDERR_FILENO);
			ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		}
		else if (cmd[2])
			return(ft_putendl_fd("minishell: exit: too many arguments",
					 STDERR_FILENO), 1);
	}
	exit_free(data, cmd_exec, ret);
	return (0);
}