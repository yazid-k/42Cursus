/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:34:14 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/04 17:28:28 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(void)
{
	char cwd[1024];

	if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("minishell: pwd:	error");
		return (1);
	}
	else
	{
		printf("%s\n", cwd);
	}
	return (0);
}
