/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:52 by ekadiri           #+#    #+#             */
/*   Updated: 2023/05/25 15:50:49 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	is_coord(av[1]);
	is_fov(av[1]);
	is_light_ratio(av[1]);
	is_measure(av[1]);
	is_name(av[1]);
	is_rgb(av[1]);
	is_vector(av[1]);
	return (0);
}
