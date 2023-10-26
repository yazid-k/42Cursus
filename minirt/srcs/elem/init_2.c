/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:38:50 by ekadiri           #+#    #+#             */
/*   Updated: 2023/09/22 15:11:00 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	get_rgb_from_string(char *s)
{
	char	**arr;
	int		ret;

	arr = ft_split(s, ',');
	if (!arr)
		return (0);
	ret = rgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
	return (free_arr(arr), ret);
}

t_coord	get_coord_from_string(char *s)
{
	t_coord	ret;
	char	**arr;

	arr = ft_split(s, ',');
	ret = coord(ft_atof(arr[0]), ft_atof(arr[1]), ft_atof(arr[2]));
	free_arr(arr);
	return (ret);
}

t_elem	*get_ambient_light(char **arr)
{
	t_elem	*ret;

	ret = elemnew();
	if (!ret)
		return (NULL);
	ret->type = A_LIGHT;
	ret->light = ft_atof(arr[1]);
	ret->rgb = get_rgb_from_string(arr[2]);
	return (ret);
}

t_elem	*get_camera(char **arr)
{
	t_elem	*ret;

	ret = elemnew();
	if (!ret)
		return (NULL);
	ret->type = CAMERA;
	ret->coord = get_coord_from_string(arr[1]);
	ret->vector = norm(get_coord_from_string(arr[2]));
	ret->fov = ft_atoi(arr[3]);
	return (ret);
}

t_elem	*get_light(char **arr)
{
	t_elem	*ret;

	ret = elemnew();
	if (!ret)
		return (NULL);
	ret->type = LIGHT;
	ret->coord = get_coord_from_string(arr[1]);
	ret->light = ft_atof(arr[2]);
	ret->rgb = get_rgb_from_string(arr[3]);
	return (ret);
}
