/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:00:17 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/29 21:38:08 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_ray	ray(t_coord origin, t_coord direction)
{
	t_ray	ret;

	ret.origin = origin;
	ret.direction = norm(direction);
	return (ret);
}

void	print_ray(t_ray r)
{
	printf("Origin : ");
	print_coord(r.origin);
	printf("Direction : ");
	print_coord(r.direction);
}
