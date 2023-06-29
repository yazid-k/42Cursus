/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:00:53 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/29 23:51:21 by ekadiri          ###   ########.fr       */
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
