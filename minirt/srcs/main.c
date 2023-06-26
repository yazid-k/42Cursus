/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:52 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/26 16:01:31 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void square(t_data *data)
{
	for (size_t i = 250; i < 750; i++)
	{
		for (size_t j = 250; j < 750; j++)
		{
			my_mlx_pixel_put(data, i, j, 0x00FF0000);
		}

	}

}

int	main(int ac, char **av)
{
	t_data	*data;

	av[1] = "scenes/scene1.rt";
	if (!parse(ac, av))
		return (1);
	data = init_struct(av[1]);
	square(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
	clear_all(data);
	return (0);
}
