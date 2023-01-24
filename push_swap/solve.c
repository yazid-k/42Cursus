/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:23:00 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 18:09:04 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve3(t_stack s)
{
	if (s.stack[0] > s.stack[1] && s.stack[1] > s.stack[2])
	{
		swap(s, 'a');
		reverse_rotate(s, 'a');
	}
	else if (s.stack[0] < s.stack[1] && s.stack[0] > s.stack[2])
		reverse_rotate(s, 'a');
	else if (s.stack[0] > s.stack[2] && s.stack[2] > s.stack[1])
		rotate(s, 'a');
	else if (s.stack[0] < s.stack[1] && s.stack[1] > s.stack[2])
	{
		swap(s, 'a');
		rotate(s, 'a');
	}
	else if (s.stack[0] > s.stack[1] && s.stack[0] < s.stack[2])
		swap(s, 'a');
}

void	insert_sort(t_stack a, t_stack b)
{
	while (a.len && !is_sorted(a))
	{
		put_on_top(a, min_index(a), 'a');
		push(&a, &b, 'b');
		if (a.len == 3 && !is_sorted(a))
			solve3(a);
	}
	while (b.len)
		push(&b, &a, 'a');
}

void	double_put_on_top(t_stack a, t_stack b, int *index)
{
	int	i;
	int	c;

	i = -1;
	if (cost(a, index[0]) < 0)
	{
		c = max(cost(a, index[0]), cost(b, index[1]));
		while (++i < -c)
			rrr(a, b, 1);
	}
	else
	{
		c = min(cost(a, index[0]), cost(b, index[1]));
		while (++i < c)
			rr(a, b, 1);
	}
}

void	rotation(t_stack a, t_stack b, int *index)
{
	int	v_a;
	int	v_b;

	v_a = a.stack[index[0]];
	v_b = b.stack[index[1]];
	double_put_on_top(a, b, index);
	put_on_top(a, get_index(a, v_a), 'a');
	put_on_top(b, get_index(b, v_b), 'b');
}

void	sort(t_stack a, t_stack b)
{
	int	*index;

	while (a.len != 3)
		push(&a, &b, 'b');
	solve3(a);
	while (b.len)
	{
		index = min_cost_indexes(a, b);
		if (cost(a, index[0]) * cost(b, index[1]) <= 0)
		{
			put_on_top(a, index[0], 'a');
			put_on_top(b, index[1], 'b');
		}
		else
			rotation(a, b, index);
		push(&b, &a, 'a');
		free(index);
	}
	put_on_top(a, min_index(a), 'a');
}
