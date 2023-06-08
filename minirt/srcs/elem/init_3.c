/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:56:33 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/08 13:30:18 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	print_elem(t_elem *elem)
{
	while (elem)
	{
		printf("Type %d Light %f RGB %d Coords %f %f %f Vector %f %f %f fov %d Diameter %f Height %f\n",elem->type, elem->light, elem->rgb, elem->coord.x, elem->coord.y, elem->coord.z, elem->vector.x, elem->vector.y, elem->coord.z, elem->fov, elem->diameter, elem->height);
		elem = elem->next;
	}
}

t_elem	*init_elem(char *file)
{
	int		fd;
	char	*s;
	char	**arr;
	t_elem	*elem;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	s = get_next_line(fd);
	if (!s)
		return (close(fd), NULL);
	elem = NULL;
	while (s)
	{
		while (s[0] == '\n')
		{
			free(s);
			s = get_next_line(fd);
			if (!s)
				return (close(fd), elem);
		}
		s[ft_strlen(s) - 1] = 0;
		arr = ft_split(s, ' ');
		if (!elem)
			elem = get_elem_from_arr(arr);
		else
			elemadd_back(&elem, get_elem_from_arr(arr));
		free_arr(arr);
		free(s);
		s = get_next_line(fd);
	}
	return (close(fd), elem);
}
