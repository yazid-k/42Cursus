/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:43:26 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/02 15:43:28 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"

void	free_pfd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_cmd)
	{
		free(data -> pfd[i]);
		i++;
	}
	free(data -> pfd);
}

int	ft_free_pipes(t_data *data, int n)
{
	int	i;

	i = -1;
	if (data -> pfd)
	{
		while (data -> pfd[++i] && i < n)
			free_pfd(data);
		free_pfd(data);
	}
	return (0);
}

