/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:29:46 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/29 22:03:33 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	hit_sphere(t_ray r, t_elem *sphere)
{
	t_coord	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec_sub(r.origin, sphere->coord);
	a = vec_dot(r.direction, r.direction);
	b = 2. * vec_dot(oc, r.direction);
	c = vec_dot(oc, oc) - sphere->diameter * sphere->diameter;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
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
		if (elem->type == SPHERE)
		{
			if (hit_sphere(r, elem) && dst > distance(r.origin, elem->coord))
			{
				dst = distance(r.origin, elem->coord);
				color = elem->rgb;
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
	double	x,y;
	t_ray	r;

	camera = get_u_elem_by_type(data, CAMERA);
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
				my_mlx_pixel_put(data, i, j, ray_color(r, data));
			else
				my_mlx_pixel_put(data, i, j, rgb(0, 0, (int)(255. * fabs(r.direction.y))));
		}
	}
}
