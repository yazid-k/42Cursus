/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:57:57 by ekadiri           #+#    #+#             */
/*   Updated: 2023/09/22 16:47:57 by ekadiri          ###   ########.fr       */
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

t_coord	coord(double x, double y, double z)
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

t_elem	*get_elem_by_type(t_data *data, t_type type)
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
