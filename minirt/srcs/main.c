/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:52 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/30 13:27:54 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	main(int ac, char **av)
{
	t_data	*data;

	av[1] = "scenes/scene1.rt";
	if (!parse(ac, av))
		return (1);
	data = init_struct(av[1]);
	render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 17, 0, close_win, &data);
	mlx_key_hook(data->win, keyhook, &data);
	mlx_loop(data->mlx);
	return (0);
}
