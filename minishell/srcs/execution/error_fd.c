/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:21:07 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/12 16:44:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	error_fd(t_token *token, t_cmd *cmd, t_data *data)
{
	if (errno == 13 && token->type != A_DLESS)
		ft_printf("%s: Permission denied\n", token->content);
	else if (token->type != A_DLESS)
		ft_printf("%s: No such file or directory\n", token->content);
	ft_close(data, cmd);
	cmdclear(cmd);
	free_lst(& data->env_lst);
	free_tab((void **)data->env_cpy);
	exit (1);
}
