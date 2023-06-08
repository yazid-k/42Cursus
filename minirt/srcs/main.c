/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:52 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/08 11:25:21 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	square(t_data *data)
{
	for (size_t i = 250; i < 750; i++)
	{
		for (size_t j = 250; j < 750; j++)
			my_mlx_pixel_put(data, i, j, create_rgb(i % 255, j % 255, 0));
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	av[1] = "scenes/scene1.rt";
	if (!parse(ac, av))
		return (1);
	data = init_struct(av[1]);
	clear_all(data);
	return (0);
}
