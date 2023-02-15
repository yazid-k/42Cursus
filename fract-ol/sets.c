/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:38:51 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/05 13:16:25 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_data *data)
{
	int			i;
	int			j;
	int			iter;
	double		pixel_size;
	t_complex	z;

	pixel_size = (data->ma.re - data->mi.re) / 1000.;
	data->set = 0;
	i = -1;
	while (++i < 1000)
	{
		z.re = data->mi.re + i * pixel_size;
		j = -1;
		while (++j < 1000)
		{
			z.im = data->ma.im - j * pixel_size;
			iter = get_color(data, z.re, z.im, data->z);
			if (iter != data->i_max)
				my_mlx_pixel_put(data, i, j,
					color_iteration(iter, data->i_max, data));
			else
				my_mlx_pixel_put(data, i, j, 0);
		}
	}
}

void	mandelbrot(t_data *data)
{
	int			i;
	int			j;
	int			iter;
	double		pixel_size;
	t_complex	z;

	pixel_size = (data->ma.re - data->mi.re) / 1000.;
	data->set = 1;
	i = -1;
	while (++i < 1000)
	{
		z.re = data->mi.re + i * pixel_size;
		j = -1;
		while (++j < 1000)
		{
			z.im = data->ma.im - j * pixel_size;
			iter = get_color(data, 0, 0, z);
			if (iter != data->i_max)
				my_mlx_pixel_put(data, i, j,
					color_iteration(iter, data->i_max, data));
			else
				my_mlx_pixel_put(data, i, j, 0);
		}
	}
}

void	burning_ship(t_data *data)
{
	int			i;
	int			j;
	int			iter;
	double		pixel_size;
	t_complex	z;

	pixel_size = (data->ma.re - data->mi.re) / 1000.;
	data->set = 2;
	i = -1;
	while (++i < 1000)
	{
		z.re = data->mi.re + i * pixel_size;
		j = -1;
		while (++j < 1000)
		{
			z.im = - (data->ma.im - j * pixel_size);
			iter = get_color_bs(data, 0, 0, z);
			if (iter != data->i_max)
				my_mlx_pixel_put(data, i, j,
					color_iteration(iter, data->i_max, data));
			else
				my_mlx_pixel_put(data, i, j, 0);
		}
	}
}
