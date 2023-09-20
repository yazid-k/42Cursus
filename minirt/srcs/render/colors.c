/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:42:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/09/20 15:38:50 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

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
