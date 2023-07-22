/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:56:33 by ekadiri           #+#    #+#             */
/*   Updated: 2023/07/22 17:41:47 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	skip_lines(char **s, int fd)
{
	while (*s[0] == '\n')
	{
		free(*s);
		*s = get_next_line(fd);
		if (!(*s))
			return (close(fd), 0);
	}
	return (1);
}

t_elem	*init_elem(char *file)
{
	int		fd;
	char	*s;
	char	**arr;
	t_elem	*elem;

	fd = open(file, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
		return (close(fd), NULL);
	elem = NULL;
	while (s)
	{
		if (!skip_lines(&s, fd))
			return (elem);
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
