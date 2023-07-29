/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:42:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/07/29 23:45:44 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	shadow(t_coord h, t_data *data)
{
	t_ray	r;
	t_elem	*light;
	t_elem	*elem;

	light = get_elem_by_type(data, LIGHT);
	elem = data->elem;
	r = ray(h, vec_sub(light->coord, h));
	r.origin.x += 0.001 * r.direction.x;
	r.origin.y += 0.001 * r.direction.y;
	r.origin.z += 0.001 * r.direction.z;
	while (elem)
	{
		if ((elem->type == 3 || elem->type == 4))
		{
			if (isnan(hit(r, elem).x) == 0)
				return (0);
		}
		elem = elem->next;
	}
	return (1);
}

int	ambient_color(int color, t_data *data)
{
	t_elem	*a_light;
	int		ret[3];

	a_light = get_elem_by_type(data, A_LIGHT);
	if (!a_light)
		return (color);
	ret[0] = get_r(color) * a_light->light;
	ret[1] = get_g(color) * a_light->light;
	ret[2] = get_b(color) * a_light->light;
	return (rgb(ret[0], ret[1], ret[2]));
}

int	light(t_coord p, t_data *data, t_elem *elem)
{
	t_elem	*light;
	t_coord	n;
	double	ratio;

	light = get_elem_by_type(data, LIGHT);
	if (!light)
		return (ambient_color(elem->rgb, data));
	if (!shadow(p, data))
		return (0);
	n = normal(p, elem);
	ratio = fmax(0, vec_dot(n, norm(vec_sub(light->coord, p))));
	if (elem->type == PLANE && !ratio)
	{
		n.x = -n.x;
		n.y = -n.y;
		n.z = -n.z;
		ratio = fmax(0, vec_dot(n, norm(vec_sub(light->coord, p))));
	}
	return (rgb(get_r(elem->rgb) * ratio, get_g(elem->rgb) * ratio,
			get_b(elem->rgb) * ratio));
}
