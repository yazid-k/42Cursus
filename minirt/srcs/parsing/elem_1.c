/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:54:04 by ekadiri           #+#    #+#             */
/*   Updated: 2023/05/25 16:11:02 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	parse_ambient_light(char **arr)
{
	if (arr_size(arr) != 3)
		return (printf("Wrong number of parameters for ambient light\n"), 0);
	if (!is_name(arr[0]))
		return (0);
	if (!is_light_ratio(arr[1]))
		return (0);
	if (!is_rgb(arr[2]))
		return (0);
	return (1);
}

int	parse_camera(char **arr)
{
	if (arr_size(arr) != 4)
		return (printf("Wrong number of parameters for camera\n"), 0);
	if (!is_name(arr[0]))
		return (0);
	if (!is_coord(arr[1]))
		return (0);
	if (!is_vector(arr[2]))
		return (0);
	if (!is_fov(arr[3]))
		return (0);
	return (1);
}

int	parse_light(char **arr)
{
	if (arr_size(arr) != 4)
		return (printf("Wrong number of parameters for light\n"), 0);
	if (!is_name(arr[0]))
		return (0);
	if (!is_coord(arr[1]))
		return (0);
	if (!is_light_ratio(arr[2]))
		return (0);
	if (!is_rgb(arr[3]))
		return (0);
	return (1);
}

int	parse_sphere(char **arr)
{
	if (arr_size(arr) != 4)
		return (printf("Wrong number of parameters for sphere\n"), 0);
	if (!is_name(arr[0]))
		return (0);
	if (!is_coord(arr[1]))
		return (0);
	if (!is_measure(arr[2]))
		return (0);
	if (!is_rgb(arr[3]))
		return (0);
	return (1);
}

int	parse_cylinder(char **arr)
{
	if (arr_size(arr) != 6)
		return (printf("Wrong number of parameters for cylinder\n"), 0);
	if (!is_name(arr[0]))
		return (0);
	if (!is_coord(arr[1]))
		return (0);
	if (!is_vector(arr[2]))
		return (0);
	if (!is_measure(arr[3]))
		return (0);
	if (!is_measure(arr[4]))
		return (0);
	if (!is_rgb(arr[5]))
		return (0);
	return (1);
}
