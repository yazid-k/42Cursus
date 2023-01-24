/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:16:54 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 20:10:06 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (!check_args(av) || ac < 2)
	{
		if (!str_isnumber(av[1]))
			ft_printf("Error\n");
		if (ac > 2)
			ft_printf("Error\n");
		return (0);
	}
	a = init_stack(av, 1);
	b = init_stack(av, 0);
	if (a.len == 3)
		solve3(a);
	else if (a.len < 50)
		insert_sort(a, b);
	else
		sort(a, b);
	free(a.stack);
	free(b.stack);
	return (0);
}
