/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:57:40 by ekadiri           #+#    #+#             */
/*   Updated: 2025/03/22 22:12:10 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	cost(t_stack s, int index)
{
	if (index <= s.len / 2)
		return (index);
	else
		return (index - s.len);
}

int	t_cost(t_stack s_a, int a, t_stack s_b, int b)
{
	if (cost(s_a, a) < 0 && cost(s_b, b) < 0)
		return (abs(min(cost(s_a, a), cost(s_b, b))));
	if (cost(s_a, a) > 0 && cost(s_b, b) > 0)
		return (max(cost(s_a, a), cost(s_b, b)));
	return (abs(cost(s_b, b)) + abs(cost(s_a, a)));
}

int	index_to_insert(t_stack s, int n)
{
	int	i;

	if (n > s.stack[max_index(s)])
	{
		if (max_index(s) == s.len - 1)
			return (0);
		return (max_index(s) + 1);
	}
	if (n < s.stack[0] && n > s.stack[s.len - 1])
		return (0);
	if (n < s.stack[min_index(s)])
		return (min_index(s));
	i = -1;
	while (++i < s.len - 1)
	{
		if (n > s.stack[i] && n < s.stack[i + 1])
			return (i + 1);
	}
	return (i);
}
