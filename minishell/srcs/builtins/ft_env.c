/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:32:47 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/17 18:37:19 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_print_env(t_env *env_lst)
{
	t_env	*temp;

	temp = env_lst;
	while (temp)
	{
		printf("%s\n", temp->env_str);
		temp = temp->next;
	}
	return (0);
}

int	ft_env(t_env *env_lst, int len)
{
	if (len > 1)
		printf("not supported\n");
	else if (len == 1)
		ft_print_env(env_lst);
	return (0);
}
