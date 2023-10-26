/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:42:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/10/06 17:18:25 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	inside_sphere(t_coord point, t_data *data)
{
	double	dst;
	t_elem	*tmp;

	tmp = data->elem;
	while (tmp)
	{
		if (tmp->type == SPHERE)
		{
			dst = distance(point, tmp->coord);
			if (dst <= tmp->diameter / 2)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_shadowed(t_coord h, t_data *data, t_elem *e)
{
	t_coord	v;
	t_coord	direction;
	double	dst;
	t_ray	r;
	t_elem	*tmp;

	h = vec_add(h, vec_scale(normal(h, e), -0.1));
	if (inside_sphere(h, data) || e->type == CIRCLE || e->type == CYLINDER)
		return (1);
	h = vec_add(h, vec_scale(normal(h, e), 0.1));
	if (e->type == PLANE)
		h = vec_add(h, vec_scale(normal(h, e), -0.1));
	v = vec_sub(get_elem_by_type(data, LIGHT)->coord, h);
	dst = distance(coord(0, 0, 0), v);
	direction = norm(v);
	r = ray(h, direction);
	tmp = data->elem;
	while (tmp)
	{
		if (tmp->type >= 3 && !isnan(hit(r, tmp).x)
			&& distance(h, hit(r, tmp)) < dst && tmp != e)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ambient_color(int color, t_data *data)
{
	t_elem	*a_light;
	int		ret[3];

	a_light = get_elem_by_type(data, A_LIGHT);
	if (!a_light)
		return (0);
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

	if (!is_shadowed(p, data, elem))
		return (rgb(get_r(elem->rgb) * 0.1, get_g(elem->rgb) * 0.1,
				get_b(elem->rgb) * 0.1));
	light = get_elem_by_type(data, LIGHT);
	if (!light)
		return (ambient_color(elem->rgb, data));
	if (!is_shadowed(p, data, elem))
		return (rgb(get_r(elem->rgb) * 0.1, get_g(elem->rgb) * 0.1,
				get_b(elem->rgb) * 0.1));
	n = normal(p, elem);
	ratio = fmax(0, vec_dot(n, norm(vec_sub(light->coord, p)))) * light->light;
	if ((elem->type == PLANE || elem->type == CIRCLE) && !ratio)
	{
		n = vec_scale(n, -1);
		ratio = fmax(0, vec_dot(n, norm(vec_sub(light->coord, p))));
	}
	return (rgb(get_r(elem->rgb) * ratio, get_g(elem->rgb) * ratio,
			get_b(elem->rgb) * ratio));
}
