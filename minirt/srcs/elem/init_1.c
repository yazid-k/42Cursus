/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:13:30 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/08 13:43:03 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_elem	*get_sphere(char **arr)
{
	t_elem	*ret;

	ret = elemnew();
	if (!ret)
		return (NULL);
	ret->type = SPHERE;
	ret->coord = get_coord_from_string(arr[1]);
	ret->diameter = ft_atof(arr[2]);
	ret->rgb = get_rgb_from_string(arr[3]);
	return (ret);
}

t_elem	*get_plane(char **arr)
{
	t_elem	*ret;

	ret = elemnew();
	if (!ret)
		return (NULL);
	ret->type = PLANE;
	ret->coord = get_coord_from_string(arr[1]);
	ret->vector = get_coord_from_string(arr[2]);
	ret->rgb = get_rgb_from_string(arr[3]);
	return (ret);
}

t_elem	*get_cylinder(char **arr)
{
	t_elem	*ret;

	ret = elemnew();
	if (!ret)
		return (NULL);
	ret->type = CYLINDER;
	ret->coord = get_coord_from_string(arr[1]);
	ret->vector = get_coord_from_string(arr[2]);
	ret->diameter = ft_atof(arr[3]);
	ret->height = ft_atof(arr[4]);
	ret->rgb = get_rgb_from_string(arr[5]);
	return (ret);
}

t_elem	*get_cone(char **arr)
{
	t_elem	*ret;

	ret = elemnew();
	if (!ret)
		return (NULL);
	ret->type = CONE;
	ret->coord = get_coord_from_string(arr[1]);
	ret->vector = get_coord_from_string(arr[2]);
	ret->diameter = ft_atof(arr[3]);
	ret->height = ft_atof(arr[4]);
	ret->rgb = get_rgb_from_string(arr[5]);
	return (ret);
}

t_elem	*get_elem_from_arr(char **arr)
{
	int		size;

	size = ft_strlen(arr[0]);
	if (!ft_strncmp(arr[0], "A", max(size, 1)))
		return (get_ambient_light(arr));
	if (!ft_strncmp(arr[0], "C", max(size, 1)))
		return (get_camera(arr));
	if (!ft_strncmp(arr[0], "L", max(size, 1)))
		return (get_light(arr));
	if (!ft_strncmp(arr[0], "sp", max(size, 2)))
		return (get_sphere(arr));
	if (!ft_strncmp(arr[0], "cy", max(size, 2)))
		return (get_cylinder(arr));
	if (!ft_strncmp(arr[0], "pl", max(size, 2)))
		return (get_plane(arr));
	if (!ft_strncmp(arr[0], "co", max(size, 2)))
		return (get_cone(arr));
	return (NULL);
}
