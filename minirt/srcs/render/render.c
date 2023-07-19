/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:29:46 by ekadiri           #+#    #+#             */
/*   Updated: 2023/07/19 02:12:36 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	shadow_test(t_coord point, t_data *data)
{
	t_ray	r;
	t_elem	*light;
	t_elem	*elem;

	light = get_elem_by_type(data, LIGHT);
	if (!light)
		return (1);
	elem = data->elem;
	r = ray(point, vec_sub(light->coord, point));
	r.origin.x += r.direction.x * 0.1;
	r.origin.y += r.direction.y * 0.1;
	r.origin.z += r.direction.z * 0.1;
	while (elem)
	{
		if (elem->type == 3 || elem->type == 4)
		{
			if (hit(r, elem).x != NAN)
				return (1);
		}
		elem = elem->next;
	}
	return (1);
}

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
			if (hit(r, elem).x != NAN && distance(r.origin, hit(r, elem)) < dst)
			{
				dst = distance(r.origin, hit(r, elem));
				color = elem->rgb * shadow_test(hit(r, elem), data);
			}
		}
		elem = elem->next;
	}
	return (color);
}

void	render(t_data *data)
{
	t_elem	*camera;
	double	viewport_width;
	double	viewport_height;
	t_coord	bottom_left, origin;
	double	x, y;
	t_ray	r;

	camera = get_elem_by_type(data, CAMERA);
	viewport_width = 2. * tan((camera->fov / 2.) * M_PI / 180.);
	viewport_height = viewport_width * (9. / 16.);
	origin = coord(0, 0, 0);
	bottom_left = coord(-viewport_width / 2., -viewport_height / 2., -1.);
	for (int i = 0; i < 700 * 16 / 9; i++)
	{
		for (int j = 0; j < 700; j++)
		{
			x = (double)i / (700 * 16 / 9);
			y = (double)j / 700;
			r = ray(origin, vec_add(bottom_left, coord(x * viewport_width, y * viewport_height, 0)));
			if (ray_color(r, data) != 0)
				my_mlx_pixel_put(data, i, 700 - j, ray_color(r, data));
		}
	}
}
