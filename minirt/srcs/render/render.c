/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:29:46 by ekadiri           #+#    #+#             */
/*   Updated: 2023/07/22 17:44:27 by ekadiri          ###   ########.fr       */
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

void	render(t_data *data)
{
	t_elem	*camera;
	double	viewport[2];
	t_coord	bottom_left;
	double	k[2];
	t_ray	r;

	camera = get_elem_by_type(data, CAMERA);
	viewport[0] = 2. * tan((camera->fov / 2.) * M_PI / 180.);
	viewport[1] = viewport[0] * (9. / 16.);
	bottom_left = coord(-viewport[0] / 2., -viewport[1] / 2., -1.);
	for (int i = 0; i < 700 * 16 / 9; i++)
	{
		for (int j = 0; j < 700; j++)
		{
			k[0] = (double)i / (700 * 16 / 9);
			k[1] = (double)j / 700;
			r = ray(camera->coord, vec_add(bottom_left,
						coord(k[0] * viewport[0], k[1] * viewport[1], 0)));
			if (ray_color(r, data) != 0)
				my_mlx_pixel_put(data, i, 700 - j, ray_color(r, data));
		}
	}
}
