/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:37:00 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/04 20:20:05 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data	*init_struct(int max)
{
	t_data		*data;
	t_complex	mi;
	t_complex	ma;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "Fract-ol");
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->x = 0;
	data->y = 0;
	data->i_max = max;
	data->color = 0;
	ma.re = 3.;
	ma.im = 3.;
	mi.re = -3.;
	mi.im = -3.;
	data->ma = ma;
	data->mi = mi;
	return (data);
}
