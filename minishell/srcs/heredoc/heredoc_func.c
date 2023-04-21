/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:24:14 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/11 03:46:06 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_here	*herenew(void)
{
	t_here	*here;

	here = malloc(sizeof(t_here));
	if (!here)
		return (NULL);
	here->delim = NULL;
	here->next = NULL;
	return (here);
}

t_here	*herelast(t_here *here)
{
	if (!here || !here->next)
		return (here);
	here = here->next;
	return (herelast(here));
}

void	hereclear(t_here *here)
{
	t_here	*tmp;

	while (here)
	{
		tmp = here->next;
		close(here->pipe[1]);
		close(here->pipe[0]);
		free(here);
		here = tmp;
	}
}

void	hereadd_back(t_here **lst, t_here *new)
{
	t_here	*l;

	if (*lst)
	{
		l = herelast(*lst);
		if (l)
			l->next = new;
	}
}

t_here	*init_here(int n)
{
	int		i;
	t_here	*ret;

	i = 0;
	ret = herenew();
	while (++i < n)
		hereadd_back(&ret, herenew());
	return (ret);
}
