/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:26:21 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/01 18:38:55 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	parse(t_cmd *cmd)
{
	if (!parse_pipes(cmd))
		return (0);
	if (!parse_redirections(cmd))
		return (0);
	return (1);
}
