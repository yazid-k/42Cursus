/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:32:39 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/20 23:28:57 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_close(t_data *data, t_cmd *cmd_exec)
{
	(void)cmd_exec;
	close(data->pfd[0]);
	close(data->pfd[1]);
}
