/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:57:57 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/29 22:01:00 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[++i])
		;
	return (i);
}

int	rgb(int r, int g, int b)
{
	if (r > 255 || r < 0 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (b + r * (int)pow(16, 4) + g * (int)pow(16, 2));
}

t_coord	coord(float x, float y, float z)
{
	t_coord	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

void	print_coord(t_coord c)
{
	printf("x : %f y : %f z : %f\n", c.x, c.y, c.z);
}

t_elem	*get_u_elem_by_type(t_data *data, t_type type)
{
	t_elem	*tmp;

	tmp = data->elem;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
