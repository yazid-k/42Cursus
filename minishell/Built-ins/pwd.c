/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:47:42 by mvicedo           #+#    #+#             */
/*   Updated: 2023/02/21 17:52:01 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"

#include <stdio.h>
#include <unistd.h>

int	ft_pwd(void)
{
	char cwd[1024];

	if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("minishell: pwd:	error");
		return (-1);
	}
	else
		printf("%s\n", cwd);
	return (0);   
}

int main()
{
	int ret;

	ret = ft_pwd();
	return (ret);
}