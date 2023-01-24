/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:58:17 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 19:36:27 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*min_cost_indexes(t_stack a, t_stack b)
{
	int	*index;
	int	min;
	int	i;

	index = ft_calloc(sizeof(int), 2);
	if (!index)
		return (NULL);
	index[0] = index_to_insert(a, b.stack[0]);
	index[1] = 0;
	min = t_cost(a, index[0], b, index[1]);
	i = -1;
	while (++i < b.len)
	{
		if (t_cost(a, index_to_insert(a, b.stack[i]), b, i) < min)
		{
			index[0] = index_to_insert(a, b.stack[i]);
			index[1] = i;
			min = t_cost(a, index_to_insert(a, b.stack[i]), b, i);
		}
	}
	return (index);
}

int	get_index(t_stack s, int n)
{
	int	i;

	i = -1;
	while (++i < s.len)
	{
		if (s.stack[i] == n)
			return (i);
	}
	return (-1);
}
