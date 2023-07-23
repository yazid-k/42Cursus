/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:37:52 by ekadiri           #+#    #+#             */
/*   Updated: 2023/07/23 14:19:09 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_coord	vec_cross(t_coord v1, t_coord v2)
{
	return (coord(v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x));
}

t_coord	matrix_mult(t_matrix m, t_coord v)
{
	t_coord	ret;

	ret.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0];
	ret.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1];
	ret.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2];
	return (ret);
}

t_matrix	camera_matrix(t_elem *camera)
{
	t_matrix	ret;
	t_coord		u;
	t_coord		v;

	u = norm(vec_cross(coord(0., 1., 0.), camera->vector));
	v = vec_cross(camera->vector, u);
	ret.m[0][0] = u.x;
	ret.m[0][1] = u.y;
	ret.m[0][2] = u.z;
	ret.m[1][0] = v.x;
	ret.m[1][1] = v.y;
	ret.m[1][2] = v.z;
	ret.m[2][0] = camera->vector.x;
	ret.m[2][1] = camera->vector.y;
	ret.m[2][2] = camera->vector.z;
	ret.m[3][0] = camera->coord.x;
	ret.m[3][1] = camera->coord.y;
	ret.m[3][2] = camera->coord.z;
	return (ret);
}

double	positive_min(double a, double b)
{
	if (a < 0 && b < 0)
		return (NAN);
	else if (a < 0)
		return (b);
	else if (b < 0)
		return (a);
	else if (a < b)
		return (a);
	return (b);
}
