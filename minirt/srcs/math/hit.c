/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:34:07 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/29 23:50:57 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

double	hit_plane(t_ray r, t_elem *plane)
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
			return (distance(r.origin, coord(r.origin.x + t * r.direction.x,
						r.origin.y + t * r.direction.y,
						r.origin.z + t * r.direction.z)));
	}
	return (-1.);
}

double	hit_cylinder(t_ray r, t_elem *cylinder)
{
	t_coord	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec_sub(r.origin, cylinder->coord);
	a = vec_dot(r.direction, r.direction)
		- pow(vec_dot(r.direction, cylinder->vector), 2.);
	b = 2. * (vec_dot(r.direction, oc)
			- vec_dot(r.direction, cylinder->vector)
			* vec_dot(oc, cylinder->vector));
	c = vec_dot(oc, oc) - pow(vec_dot(oc, cylinder->vector), 2.)
		- pow(cylinder->diameter / 2., 2.);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.);
	return (1);
}

double	hit_sphere(t_ray r, t_elem *sphere)
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
		return (-1.);
	t = min((-b + sqrt(b * b - 4 * a * c)) / (2. * a),
			(-b - sqrt(b * b - 4 * a * c)) / (2. * a));
	return (distance(r.origin, coord(r.direction.x * t,
				r.direction.y * t, r.direction.z * t)));
}

double	hit(t_ray r, t_elem *elem)
{
	if (elem->type == PLANE)
		return (hit_plane(r, elem));
	else if (elem->type == SPHERE)
		return (hit_sphere(r, elem));
	return (0.);
}
