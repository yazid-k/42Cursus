/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:42:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/08/17 01:01:14 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	shadow_func(t_elem *light, t_elem *elem, t_elem *e, t_coord p)
{
	t_coord	n;
	t_coord	origin;
	t_ray	r;

	n = normal(p, e);
	origin = vec_add(p, vec_scale(n, 0.001));
	r = ray(origin, norm(vec_sub(light->coord, origin)));
	if (!isnan(hit(r, elem).x) && (e->type == SPHERE || e->type == PLANE))
	{
		n = vec_scale(n, -1);
		origin = vec_add(p, vec_scale(n, 0.001));
		r = ray(origin, norm(vec_sub(light->coord, origin)));
	}
	if (!isnan(hit(r, elem).x))
		return (0);
	return (1);
}

int	shadow(t_coord h, t_data *data, t_elem *e)
{
	t_elem	*light;
	t_elem	*elem;

	light = get_elem_by_type(data, LIGHT);
	elem = data->elem;
	while (elem)
	{
		if (elem->type >= 3)
		{
			if (!shadow_func(light, elem, e, h))
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
	if (!shadow(p, data, elem))
		return (0);
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
