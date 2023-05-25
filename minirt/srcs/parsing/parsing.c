/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:31:04 by ekadiri           #+#    #+#             */
/*   Updated: 2023/05/25 12:07:57 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	free_arr(void **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(arr);
}

int	check_elem(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while(line)
	{
		while (line && line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
		}
		if (line == NULL)
			break ;
		if (parse_line(line))
			return(free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parse(int ac, char **av)
{
	int	len;
	int	fd;

	if (ac != 2)
		return(printf("Arg number error\n"));
	len = ft_strlen(av[1]);
	if (av[1][len -1] != 't' || av[1][len -2] != 'r' || av[1][len -3] != '.')
		return (printf("File name error\n"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (printf("File not existant\n"));
	return (check_elem(fd));
}


