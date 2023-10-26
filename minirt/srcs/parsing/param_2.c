/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:46:49 by ekadiri           #+#    #+#             */
/*   Updated: 2023/09/22 16:24:04 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	is_fov(char *param)
{
	if (!str_is_int(param))
		return (printf("Error in FOV format %s\n", param), 0);
	if (ft_atoi(param) <= 0 || ft_atoi(param) >= 180)
		return (printf("FOV out of range\n"), 0);
	return (1);
}

int	is_measure(char *param)
{
	if (!str_is_double(param))
		return (printf("Error in measure parameter %s\n", param), 0);
	if (ft_atof(param) <= 0.0)
		return (printf("Measure out of range %s\n", param), 0);
	return (1);
}
