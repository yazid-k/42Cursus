/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:36:07 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/05 13:12:06 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update(int keycode, t_data *data)
{
	if (keycode == XK_r)
		data->color = 1;
	else if (keycode == XK_g)
		data->color = 2;
	else if (keycode == XK_b)
		data->color = 0;
	else if (keycode == XK_equal)
		data->i_max += 10;
	else if (keycode == XK_minus)
		data->i_max -= 10;
	if (data->set == 0)
		julia(data);
	else if (data->set == 1)
		mandelbrot(data);
	else if (data->set == 2)
		burning_ship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
}

void	move(int keycode, t_data *data)
{
	t_complex	offset;

	offset.re = data->ma.re - data->mi.re;
	offset.im = data->ma.im - data->mi.im;
	if (keycode == XK_Up)
	{
		data->ma.im -= offset.im / 5;
		data->mi.im -= offset.im / 5;
	}
	else if (keycode == XK_Down)
	{
		data->ma.im += offset.re / 5;
		data->mi.im += offset.re / 5;
	}
	else if (keycode == XK_Right)
	{
		data->ma.re -= offset.re / 5;
		data->mi.re -= offset.re / 5;
	}
	else if (keycode == XK_Left)
	{
		data->ma.re += offset.re / 5;
		data->mi.re += offset.re / 5;
	}
	update(keycode, data);
}

int	mouse(int keycode, int x, int y, t_data *data)
{
	double	x_ratio;
	double	y_ratio;
	double	delta_re;
	double	delta_im;
	double	zoom;

	zoom = 0.0;
	if (keycode != 4 && keycode != 5)
		return (0);
	x_ratio = (double)x / 1000.;
	y_ratio = (double)y / 1000.;
	delta_re = data->ma.re - data->mi.re;
	delta_im = data->ma.im - data->mi.im;
	if (keycode == 4)
		zoom = 0.8;
	else if (keycode == 5)
		zoom = 1. / 0.8;
	delta_re = (zoom * delta_re) - delta_re;
	delta_im = (zoom * delta_im) - delta_im;
	data->mi.re -= delta_re * x_ratio;
	data->ma.re += delta_re * (1 - x_ratio);
	data->ma.im += delta_im * y_ratio;
	data->mi.im -= delta_im * (1 - y_ratio);
	return (update(0, data), 1);
}

int	keyboard(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data);
		exit(0);
	}
	else if (keycode == XK_Up || keycode == XK_Down
		|| keycode == XK_Right || keycode == XK_Left)
		move(keycode, data);
	else if (keycode == XK_r || keycode == XK_b || keycode == XK_g
		|| keycode == XK_minus || keycode == XK_equal)
		update(keycode, data);
	return (0);
}

int	close_cross(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
	return (0);
}
