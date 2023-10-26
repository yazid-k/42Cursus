/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:14:03 by ekadiri           #+#    #+#             */
/*   Updated: 2023/09/12 15:41:48 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	free_all(t_data *data)
{
	elemclear(&(data->elem));
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}

t_data	*init_struct(char *file)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->elem = init_elem(file);
	if (!data->elem)
		return (free(data), NULL);
	data->cam = get_elem_by_type(data, CAMERA);
	if (!data->cam)
		return (free(data), elemclear(&(data->elem)), NULL);
	data->mat = camera_matrix(get_elem_by_type(data, CAMERA));
	add_circles(data->elem);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 700 * 16 / 9, 700, "minirt");
	data->img = mlx_new_image(data->mlx, 700 * 16 / 9, 700);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (data);
}

int	close_win(t_data **data)
{
	free_all(*data);
	exit(0);
}

int	keyhook(int keycode, t_data **data)
{
	if (keycode == 0xff1b)
		close_win(data);
	return (0);
}
