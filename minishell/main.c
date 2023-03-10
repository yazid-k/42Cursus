/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:34:30 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/08 19:35:28 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	t_token	*t;
	t_cmd	*cmd;

	t = init_tokens(av[ac - 1]);
	cmd = create_all_cmd(t);
	print_cmd(cmd);
	cmdclear(cmd);
	tokenclear(t);
	return (0);
}
