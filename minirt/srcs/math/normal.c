/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:11:39 by ekadiri           #+#    #+#             */
/*   Updated: 2023/08/15 19:34:40 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_coord	normal_sphere(t_coord hit, t_elem *elem)
{
	return (norm(vec_sub(hit, elem->coord)));
}

t_coord	normal_cylinder(t_coord hit, t_elem *elem)
{
	t_coord	normal;
	t_coord	diff;

	diff = vec_sub(hit, elem->coord);
	normal = norm(diff);
	if (fabs(normal.x) <= 1e-5 && fabs(normal.y) <= 1e-5)
		normal = elem->vector;
	return (normal);
}

t_coord	normal(t_coord hit, t_elem *elem)
{
	if (elem->type == PLANE)
		return (elem->vector);
	else if (elem->type == SPHERE)
		return (normal_sphere(hit, elem));
	else if (elem->type == CYLINDER)
		return (normal_cylinder(hit, elem));
	return (coord(NAN, NAN, NAN));
}
