/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:52 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/08 13:44:39 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	square(t_data *data)
{
	for (size_t i = 250; i < 750; i++)
	{
		for (size_t j = 250; j < 750; j++)
			my_mlx_pixel_put(data, i, j, rgb(i % 255, j % 255, 0));
	}
}

int	main(int ac, char **av)
{
	t_elem	*elem;

	av[1] = "scenes/scene1.rt";
	if (!parse(ac, av))
		return (1);
	elem = init_elem(av[1]);
	print_elem(elem);
	elemclear(&elem);
	printf("%f\n", distance(coord(100., 100., 100.), coord(0., 0., 0.)));
	return (0);
}
