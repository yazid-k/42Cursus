/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:05:07 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 20:11:54 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_instructions(char *str)
{
	if (!ft_strncmp(str, "ss\n", 3))
		return (1);
	if (!ft_strncmp(str, "sa\n", 3))
		return (1);
	if (!ft_strncmp(str, "sb\n", 3))
		return (1);
	if (!ft_strncmp(str, "ra\n", 3))
		return (1);
	if (!ft_strncmp(str, "rb\n", 3))
		return (1);
	if (!ft_strncmp(str, "rr\n", 3))
		return (1);
	if (!ft_strncmp(str, "pa\n", 3))
		return (1);
	if (!ft_strncmp(str, "pb\n", 3))
		return (1);
	if (!ft_strncmp(str, "rra\n", 4))
		return (1);
	if (!ft_strncmp(str, "rrb\n", 4))
		return (1);
	if (!ft_strncmp(str, "rrr\n", 4))
		return (1);
	return (0);
}

void	do_op(t_stack a, t_stack b, char *str)
{
	if (!ft_strncmp(str, "ss\n", 3))
		ss(a, b);
	if (!ft_strncmp(str, "sa\n", 3))
		swap(a, 0);
	if (!ft_strncmp(str, "sb\n", 3))
		swap(b, 0);
	if (!ft_strncmp(str, "ra\n", 3))
		rotate(a, 0);
	if (!ft_strncmp(str, "rb\n", 3))
		rotate(b, 0);
	if (!ft_strncmp(str, "rr\n", 3))
		rr(a, b, 0);
	if (!ft_strncmp(str, "pa\n", 3))
		push(&b, &a, 0);
	if (!ft_strncmp(str, "pb\n", 3))
		push(&a, &b, 0);
	if (!ft_strncmp(str, "rra\n", 4))
		reverse_rotate(a, 0);
	if (!ft_strncmp(str, "rrb\n", 4))
		reverse_rotate(b, 0);
	if (!ft_strncmp(str, "rrr\n", 4))
		rrr(a, b, 0);
	free(str);
}

int	free_stacks(t_stack a, t_stack b, char *str, int error)
{
	if (error)
		ft_printf("Error\n");
	free(a.stack);
	free(b.stack);
	free(str);
	return (0);
}

void	check_result(t_stack a, t_stack b)
{
	if (!is_sorted(a))
		ft_printf("KO\n");
	else if (is_sorted(a) && b.len == 0)
		ft_printf("OK\n");
}

int	main(int ac, char *av[])
{
	char	*str;
	t_stack	a;
	t_stack	b;

	if (!check_args(av) || ac < 2)
	{
		if (ac > 2 || !str_isnumber(av[1]))
			ft_printf("Error\n");
		return (0);
	}
	a = init_stack(av, 1);
	b = init_stack(av, 0);
	str = get_next_line(0);
	while (str)
	{
		if (!check_instructions(str))
			return (free_stacks(a, b, str, 1));
		do_op(a, b, str);
		str = get_next_line(0);
	}
	check_result(a, b);
	free_stacks(a, b, str, 0);
	return (1);
}
