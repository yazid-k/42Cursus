/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:29:46 by ekadiri           #+#    #+#             */
/*   Updated: 2023/07/22 20:45:37 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	ray_color(t_ray r, t_data *data)
{
	t_elem	*elem;
	double	dst;
	int		color;

	color = 0;
	elem = data->elem;
	dst = INFINITY;
	while (elem)
	{
		if (elem->type == 3 || elem->type == 4)
		{
			if (!isnan(hit(r, elem).x)
				&& distance(r.origin, hit(r, elem)) < dst)
			{
				dst = distance(r.origin, hit(r, elem));
				color = elem->rgb;
			}
		}
		elem = elem->next;
	}
	return (color);
}

void	cast_ray(t_data *data, int i, int j, double viewport[2])
{
	t_elem	*camera;
	t_ray	r;
	t_coord	bl;
	double	k[2];
	t_coord	direction;

	camera = get_elem_by_type(data, CAMERA);
	bl = coord(-viewport[0] / 2., -viewport[1] / 2., -1.);
	k[0] = (double)i / (700 * 16 / 9);
	k[1] = (double)j / 700;
	direction = coord(bl.x + k[0] * viewport[0], bl.y + k[1] * viewport[1], 1.);
	direction = matrix_mult(camera_matrix(camera), direction);
	direction = vec_sub(direction, camera->coord);
	r = ray(camera->coord, norm(direction));
	if (ray_color(r, data))
		my_mlx_pixel_put(data, i, 700 - j, ray_color(r, data));
}

void	render(t_data *data)
{
	t_elem	*camera;
	double	viewport[2];
	int		i;
	int		j;

	camera = get_elem_by_type(data, CAMERA);
	viewport[0] = 2. * tan((camera->fov / 2.) * M_PI / 180.);
	viewport[1] = viewport[0] * (9. / 16.);
	i = 0;
	while (++i < 700 * 16 / 9)
	{
		j = 0;
		while (++j < 700)
			cast_ray(data, i, j, viewport);
	}
}
