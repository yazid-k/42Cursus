/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:30:00 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/04 20:46:36 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_complex	c;
	t_data		*data;

	if (!parse(ac, av))
		return (0);
	data = init_struct(40);
	if (!ft_strncmp(av[1], "Mandelbrot", 10))
		mandelbrot(data);
	if (!ft_strncmp(av[1], "Julia", 5))
	{
		c.re = ft_atof(av[2]);
		c.im = ft_atof(av[3]);
		data->z = c;
		julia(data);
	}
	else if (!ft_strncmp(av[1], "BurningShip", 11))
		burning_ship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, keyboard, data);
	mlx_mouse_hook(data->win, mouse, data);
	mlx_hook(data->win, 17, 1L << 17, close_cross, data);
	mlx_loop(data->mlx);
	return (1);
}
