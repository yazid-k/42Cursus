/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:59:35 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 18:58:09 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(char **av, int empty)
{
	int		i;
	t_stack	s;

	i = 0;
	while (av[i])
		i++;
	s.stack = ft_calloc(i, sizeof(int));
	if (!s.stack)
		return (s);
	s.max_size = i;
	if (!empty)
	{
		s.len = 0;
		return (s);
	}
	s.len = i - 1;
	i = 0;
	while (av[++i])
		s.stack[i - 1] = ft_atoi(av[i]);
	return (s);
}

int	min_index(t_stack s)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (++i < s.len)
	{
		if (s.stack[i] < s.stack[index])
			index = i;
	}
	return (index);
}

int	max_index(t_stack s)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (++i < s.len)
	{
		if (s.stack[i] > s.stack[index])
			index = i;
	}
	return (index);
}

void	put_on_top(t_stack s, int index, char c)
{
	int	i;

	if (index <= s.len / 2)
	{
		i = index + 1;
		while (--i > 0)
			rotate (s, c);
		return ;
	}
	i = s.len - index + 1;
	while (--i > 0)
		reverse_rotate (s, c);
}

int	is_sorted(t_stack s)
{
	int	i;

	i = -1;
	while (++i < s.len - 1)
	{
		if (s.stack[i] > s.stack[i + 1])
			return (0);
	}
	return (1);
}
