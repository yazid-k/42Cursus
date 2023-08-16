/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:34:07 by ekadiri           #+#    #+#             */
/*   Updated: 2023/08/16 01:03:54 by ekadiri          ###   ########.fr       */
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
	c = vec_dot(oc, oc) - (sphere->diameter * sphere->diameter / 4);
	if (b * b - 4 * a * c < 0)
		return (coord(NAN, NAN, NAN));
	t = pos_min((-b + sqrt(b * b - 4 * a * c)) / (2 * a),
			(-b - sqrt(b * b - 4 * a * c)) / (2 * a));
	if (isnan(t))
		return (coord(NAN, NAN, NAN));
	return (coord(r.origin.x + t * r.direction.x,
			r.origin.y + t * r.direction.y,
			r.origin.z + t * r.direction.z));
}

t_coord	hit_circle(t_ray r, t_elem *cy)
{
	t_elem	circle[2];

	circle[0].coord = cy->coord;
	circle[0].vector = cy->vector;
	circle[0].diameter = cy->diameter;
	circle[1].coord = vec_add(cy->coord, vec_scale(cy->vector, cy->height));
	circle[1].vector = cy->vector;
	circle[1].diameter = cy->diameter;
	(void)r;
	return (coord(NAN, NAN, NAN));
}

t_coord	hit_cylinder(t_ray r, t_elem *cy)
{
	double	v[5];
	t_coord	c[3];

	c[0] = vec_sub(r.origin, cy->coord);
	v[0] = vec_dot(r.direction, r.direction)
		- vec_dot(r.direction, cy->vector) * vec_dot(r.direction, cy->vector);
	v[1] = 2 * (vec_dot(r.direction, c[0])
			- vec_dot(r.direction, cy->vector) * vec_dot(c[0], cy->vector));
	v[3] = vec_dot(c[0], c[0])
		- vec_dot(c[0], cy->vector) * vec_dot(c[0], cy->vector)
		- (cy->diameter * cy->diameter / 4);
	if (v[1] * v[1] - 4 * v[0] * v[3] < 0)
		return (coord(NAN, NAN, NAN));
	v[4] = pos_min((-v[1] + sqrt(v[1] * v[1] - 4 * v[0] * v[3])) / (2 * v[0]),
			(-v[1] - sqrt(v[1] * v[1] - 4 * v[0] * v[3])) / (2 * v[0]));
	if (isnan(v[4]))
		return (coord(NAN, NAN, NAN));
	c[1] = coord(r.origin.x + v[4] * r.direction.x,
			r.origin.y + v[4] * r.direction.y,
			r.origin.z + v[4] * r.direction.z);
	c[2] = vec_sub(c[1], cy->coord);
	v[4] = vec_dot(c[2], cy->vector);
	if (v[4] < 0 || v[4] > cy->height)
		return (coord(NAN, NAN, NAN));
	return (c[1]);
}


t_coord	hit(t_ray r, t_elem *elem)
{
	if (elem->type == PLANE)
		return (hit_plane(r, elem));
	else if (elem->type == SPHERE)
		return (hit_sphere(r, elem));
	else if (elem->type == CYLINDER)
		return (hit_cylinder(r, elem));
	return (coord(NAN, NAN, NAN));
}
