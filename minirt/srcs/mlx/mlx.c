/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:14:03 by ekadiri           #+#    #+#             */
/*   Updated: 2023/08/16 01:43:18 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data	*init_struct(char *file)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 700 * 16 / 9, 700, "minirt");
	data->img = mlx_new_image(data->mlx, 700 * 16 / 9, 700);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->elem = init_elem(file);
	add_circles(data->elem);
	data->mat = camera_matrix(get_elem_by_type(data, CAMERA));
	data->cam = get_elem_by_type(data, CAMERA);
	return (data);
}

int	close_win(t_data **data)
{
	mlx_destroy_window((*data)->mlx, (*data)->win);
	exit(0);
}

int	keyhook(int keycode, t_data **data)
{
	if (keycode == 53)
		close_win(data);
	return (0);
}
