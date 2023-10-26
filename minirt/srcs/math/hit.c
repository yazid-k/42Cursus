/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:34:07 by ekadiri           #+#    #+#             */
/*   Updated: 2023/09/22 16:47:57 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_coord	hit_plane(t_ray r, t_elem *plane)
{
	double	denom;
	double	t;
	t_coord	oc;

	denom = vec_dot(plane->vector, r.dir);
	if (denom)
	{
		oc = vec_sub(plane->coord, r.origin);
		t = vec_dot(oc, plane->vector) / denom;
		if (t >= 1e-6)
			return (coord(r.origin.x + t * r.dir.x,
					r.origin.y + t * r.dir.y,
					r.origin.z + t * r.dir.z));
	}
	denom = vec_dot(vec_scale(plane->vector, -1), r.dir);
	if (denom)
	{
		oc = vec_sub(plane->coord, r.origin);
		t = vec_dot(oc, vec_scale(plane->vector, -1)) / denom;
		if (t >= 1e-6)
			return (coord(r.origin.x + t * r.dir.x,
					r.origin.y + t * r.dir.y,
					r.origin.z + t * r.dir.z));
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
	a = vec_dot(r.dir, r.dir);
	b = 2. * vec_dot(oc, r.dir);
	c = vec_dot(oc, oc) - (sphere->diameter * sphere->diameter / 4);
	if (b * b - 4 * a * c < 0)
		return (coord(NAN, NAN, NAN));
	t = pos_min((-b + sqrt(b * b - 4 * a * c)) / (2 * a),
			(-b - sqrt(b * b - 4 * a * c)) / (2 * a));
	if (isnan(t))
		return (coord(NAN, NAN, NAN));
	return (coord(r.origin.x + t * r.dir.x,
			r.origin.y + t * r.dir.y,
			r.origin.z + t * r.dir.z));
}

t_coord	hit_circle(t_ray r, t_elem *circle)
{
	t_coord	p_hit;

	p_hit = hit_plane(r, circle);
	if (isnan(p_hit.x))
		return (coord(NAN, NAN, NAN));
	if (distance(p_hit, circle->coord) > circle->diameter / 2)
		return (coord(NAN, NAN, NAN));
	return (p_hit);
}

t_coord	hit_cylinder(t_ray r, t_elem *cy)
{
	t_coord	x;
	double	p[5];
	double	t;
	t_coord	ip;

	p[0] = vec_dot(r.dir, r.dir) - pow(vec_dot(r.dir, cy->vector), 2.);
	x = vec_sub(r.origin, cy->coord);
	p[1] = vec_dot(x, x) - pow(vec_dot(x, cy->vector), 2.)
		- (pow(cy->diameter / 2, 2.));
	p[2] = 2 * (vec_dot(r.dir, x) - vec_dot(r.dir, cy->vector)
			* vec_dot(x, cy->vector));
	p[4] = p[2] * p[2] - 4 * p[0] * p[1];
	if (p[4] < 0)
		return (coord(NAN, NAN, NAN));
	t = fmin((-p[2] + sqrt(p[4])) / (2 * p[0]),
			(-p[2] - sqrt(p[4])) / (2 * p[0]));
	if (isnan(t))
		return (coord(NAN, NAN, NAN));
	ip = coord(r.origin.x + t * r.dir.x,
			r.origin.y + t * r.dir.y,
			r.origin.z + t * r.dir.z);
	p[3] = vec_dot(vec_sub(ip, cy->coord), cy->vector);
	if (p[3] < 0 || p[3] > cy->height)
		return (coord(NAN, NAN, NAN));
	return (ip);
}

t_coord	hit(t_ray r, t_elem *elem)
{
	if (elem->type == PLANE)
		return (hit_plane(r, elem));
	else if (elem->type == SPHERE)
		return (hit_sphere(r, elem));
	else if (elem->type == CYLINDER)
		return (hit_cylinder(r, elem));
	else if (elem->type == CIRCLE)
		return (hit_circle(r, elem));
	return (coord(NAN, NAN, NAN));
}
