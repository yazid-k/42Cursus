/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:43:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 15:33:30 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	msg_error1(char *err)
// {
// 	perror(err);
// }

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	err_msg(char *cmd, char *msg)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}
