/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:34:07 by ekadiri           #+#    #+#             */
/*   Updated: 2023/07/22 20:35:59 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_coord	hit_plane(t_ray r, t_elem *plane)
{
	double	denom;
	double	t;
	t_coord	oc;

	denom = vec_dot(plane->vector, r.direction);
	if (denom)
	{
		oc = vec_sub(plane->coord, r.origin);
		t = vec_dot(oc, plane->vector) / denom;
		if (t >= 0)
			return (coord(r.origin.x + t * r.direction.x,
					r.origin.y + t * r.direction.y,
					r.origin.z + t * r.direction.z));
	}
	return (coord(NAN, NAN, NAN));
}

t_coord	hit_sphere(t_ray r, t_elem *sphere)
{
	t_coord	oc;
	double	a;
	double	b;
	double	c;
	double	t;

	oc = vec_sub(r.origin, sphere->coord);
	a = vec_dot(r.direction, r.direction);
	b = 2. * vec_dot(oc, r.direction);
	c = vec_dot(oc, oc) - sphere->diameter * sphere->diameter;
	if (b * b - 4 * a * c < 0)
		return (coord(NAN, NAN, NAN));
	t = positive_min((-b + sqrt(b * b - 4 * a * c)) / (2 * a),
			(-b - sqrt(b * b - 4 * a * c)) / (2 * a));
	if (isnan(t))
		return (coord(NAN, NAN, NAN));
	return (coord(r.origin.x + t * r.direction.x,
			r.origin.y + t * r.direction.y,
			r.origin.z + t * r.direction.z));
}

t_coord	hit(t_ray r, t_elem *elem)
{
	if (elem->type == PLANE)
		return (hit_plane(r, elem));
	else if (elem->type == SPHERE)
		return (hit_sphere(r, elem));
	return (coord(NAN, NAN, NAN));
}
