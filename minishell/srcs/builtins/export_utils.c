/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:10:00 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/12 16:42:35 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	export_msg(char *str)
{
	return (ft_printf("export: '%s' : not a valid identifier\n", str), 1);
}

int	ft_check_input(char *str)
	{
	if (*str == '=' || *str == '+' || ft_isdigit(*str))
		return (0);
	while (*str && *str != '=')
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (0);
		str++;
	}
	return (ADD);
}

int	ft_export_var(t_env *env_lst, char *str)
{
	int	i_equal;

	i_equal = ft_is_equal(str);
	if (i_equal > 0)
	{
		if (ft_check_input(str) == ADD)
		{
			if (ft_is_new_var(env_lst, str, i_equal))
				return (ADD);
			else
				ft_update_var(env_lst, str, i_equal);
		}
	}
	return (i_equal);
}
