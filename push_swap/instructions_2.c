/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:06:28 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 19:06:47 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack stack1, t_stack stack2)
{
	swap(stack1, 0);
	swap(stack2, 0);
}

void	rr(t_stack stack1, t_stack stack2, int i)
{
	rotate(stack1, 0);
	rotate(stack2, 0);
	if (i)
		ft_printf("rr\n");
}

void	rrr(t_stack stack1, t_stack stack2, int i)
{
	reverse_rotate(stack1, 0);
	reverse_rotate(stack2, 0);
	if (i)
		ft_printf("rrr\n");
}
