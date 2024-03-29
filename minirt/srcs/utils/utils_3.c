/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:00:17 by ekadiri           #+#    #+#             */
/*   Updated: 2023/09/22 16:47:57 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_ray	ray(t_coord origin, t_coord direction)
{
	t_ray	ret;

	ret.origin = origin;
	ret.dir = norm(direction);
	return (ret);
}

void	print_ray(t_ray r)
{
	printf("Origin : ");
	print_coord(r.origin);
	printf("Direction : ");
	print_coord(r.dir);
}

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
