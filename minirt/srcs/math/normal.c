/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:11:39 by ekadiri           #+#    #+#             */
/*   Updated: 2023/08/16 03:46:46 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_coord	normal_sphere(t_coord hit, t_elem *elem)
{
	return (norm(vec_sub(hit, elem->coord)));
}

t_coord	normal_cylinder(t_coord hit, t_elem *elem)
{
	t_coord oc;
	t_coord n;

	oc = vec_sub(hit, elem->coord);
	n = vec_sub(oc, vec_scale(elem->vector, vec_dot(elem->vector, oc)));
	return (norm(n));
}

t_coord	normal(t_coord hit, t_elem *elem)
{
	if (elem->type == PLANE)
		return (elem->vector);
	else if (elem->type == SPHERE)
		return (normal_sphere(hit, elem));
	else if (elem->type == CYLINDER)
		return (normal_cylinder(hit, elem));
	else if (elem->type == CIRCLE)
		return (elem->vector);
	return (coord(NAN, NAN, NAN));
}
