/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:44:47 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 18:07:17 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack s, char c)
{
	int	tmp;

	if (s.len < 2)
		return ;
	tmp = s.stack[0];
	s.stack[0] = s.stack[1];
	s.stack[1] = tmp;
	if (c)
		ft_printf("s%c\n", c);
}

void	push(t_stack *out, t_stack *in, char c)
{
	int	i;

	if (!out->len)
		return ;
	in->len += 1;
	i = in->len;
	while (--i > 0)
		in->stack[i] = in->stack[i - 1];
	in->stack[0] = out->stack[0];
	i = -1;
	out->len -= 1;
	while (++i < out->len)
		out->stack[i] = out->stack[i + 1];
	if (c)
		ft_printf("p%c\n", c);
}

void	rotate(t_stack s, char c)
{
	int	i;
	int	first;

	first = s.stack[0];
	i = 0;
	while (++i < s.len)
		s.stack[i - 1] = s.stack[i];
	s.stack[s.len - 1] = first;
	if (c)
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stack s, char c)
{
	int	i;
	int	last;

	last = s.stack[s.len - 1];
	i = s.len - 1;
	while (--i > -1)
		s.stack[i + 1] = s.stack[i];
	s.stack[0] = last;
	if (c)
		ft_printf("rr%c\n", c);
}
