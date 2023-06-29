/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:31:04 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/29 23:49:49 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	parse(int ac, char **av)
{
	int	len;
	int	fd;

	if (ac != 2)
		return (printf("Arg number error\n"), 0);
	len = ft_strlen(av[1]);
	if (av[1][len -1] != 't' || av[1][len -2] != 'r' || av[1][len -3] != '.')
		return (printf("File name error\n"), 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (printf("File not existant\n"), 0);
	return (parse_elem(fd));
}

int	parse_unique_elem(char **arr)
{
	int			size;
	static int	a = 0;
	static int	c = 0;
	static int	l = 0;

	size = ft_strlen(arr[0]);
	if (!ft_strncmp(arr[0], "A", max(size, 1)))
	{
		if (++a > 1)
			return (printf("Ambient light declared more than once\n"), 0);
		return (parse_ambient_light(arr));
	}
	if (!ft_strncmp(arr[0], "C", max(size, 1)))
	{
		if (++c > 1)
			return (printf("Camera declared more than once\n"), 0);
		return (parse_camera(arr));
	}
	if (!ft_strncmp(arr[0], "L", max(size, 1)))
	{
		if (++l > 1)
			return (printf("Light declared more than once\n"), 0);
		return (parse_light(arr));
	}
	return (0);
}

int	parse_arr(char **arr)
{
	int			size;

	size = ft_strlen(arr[0]);
	if (!is_name(arr[0]))
		return (0);
	if (!ft_strncmp(arr[0], "L", max(size, 1))
		|| !ft_strncmp(arr[0], "C", max(size, 1))
		|| !ft_strncmp(arr[0], "A", max(size, 1)))
		return (parse_unique_elem(arr));
	if (!ft_strncmp(arr[0], "sp", max(size, 2)))
		return (parse_sphere(arr));
	if (!ft_strncmp(arr[0], "cy", max(size, 2)))
		return (parse_cylinder(arr));
	if (!ft_strncmp(arr[0], "pl", max(size, 2)))
		return (parse_plane(arr));
	return (0);
}

int	parse_elem(int fd)
{
	char	*s;
	char	**arr;

	s = get_next_line(fd);
	if (!s)
		return (close(fd), 1);
	while (s)
	{
		while (s[0] == '\n')
		{
			free(s);
			s = get_next_line(fd);
			if (!s)
				return (close(fd), 1);
		}
		s[ft_strlen(s) - 1] = 0;
		arr = ft_split(s, ' ');
		if (!parse_arr(arr))
			return (close(fd), free_arr(arr), free(s), 0);
		free_arr(arr);
		free(s);
		s = get_next_line(fd);
	}
	return (close(fd), 1);
}
