/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:26:41 by ekadiri           #+#    #+#             */
/*   Updated: 2023/09/22 16:47:57 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

double	distance(t_coord v1, t_coord v2)
{
	return (sqrt(pow(v1.x - v2.x, 2.) + pow(v1.y - v2.y, 2.)
			+ pow(v1.z - v2.z, 2.)));
}

t_coord	norm(t_coord v)
{
	double	dst;

	dst = distance(coord(0., 0., 0.), v);
	return (coord(v.x / dst, v.y / dst, v.z / dst));
}

t_coord	vec_add(t_coord v1, t_coord v2)
{
	return (coord(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_coord	vec_sub(t_coord v1, t_coord v2)
{
	return (coord(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

double	vec_dot(t_coord v1, t_coord v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
