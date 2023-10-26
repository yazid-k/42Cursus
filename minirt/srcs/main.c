/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:52 by ekadiri           #+#    #+#             */
/*   Updated: 2023/09/22 09:21:45 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (!parse(ac, av))
		return (1);
	data = init_struct(av[1]);
	if (!data)
		return (printf("Error\n"), 0);
	render(data);
	printf("Render finished\n");
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, keyhook, &data);
	mlx_hook(data->win, 17, 1L << 17, close_win, &data);
	mlx_loop(data->mlx);
	return (0);
}
