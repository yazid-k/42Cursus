/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:00:53 by ekadiri           #+#    #+#             */
/*   Updated: 2023/05/25 16:52:07 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	parse_plane(char **arr)
{
	if (arr_size(arr) != 4)
		return (printf("Wrong number of parameters for plane\n"), 0);
	if (!is_name(arr[0]))
		return (0);
	if (!is_coord(arr[1]))
		return (0);
	if (!is_vector(arr[2]))
		return (0);
	if (!is_rgb(arr[3]))
		return (0);
	return (1);
}

int	parse_cone(char **arr)
{
	if (arr_size(arr) != 6)
		return (printf("Wrong number of parameters for cone\n"), 0);
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
