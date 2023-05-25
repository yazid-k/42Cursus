/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:00:52 by ekadiri           #+#    #+#             */
/*   Updated: 2023/05/25 17:17:51 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	is_coord(char *param)
{
	char	**arr;
	int		i;

	if (!param)
		return (0);
	arr = ft_split(param, ',');
	if (!arr)
		return (0);
	i = 0;
	while (arr[++i])
		;
	if (i != 3)
		return (free_arr(arr),
			printf("Error in coord parameter %s\n", param), 0);
	i = -1;
	while (arr[++i])
	{
		if (!str_is_float(arr[i]))
			return (free_arr(arr),
				printf("Error in coord parameter %s\n", param), 0);
	}
	return (free_arr(arr), 1);
}

int	is_light_ratio(char *param)
{
	if (!str_is_float(param))
		return (printf("Error in light ratio parameter %s\n", param), 0);
	if (ft_atof(param) < -1.0 || ft_atof(param) > 1.0)
		return (printf("Light ratio out of range %s\n", param), 0);
	return (1);
}

int	is_name(char *param)
{
	size_t	size;

	if (!param)
		return (0);
	size = ft_strlen(param);
	if (ft_strncmp(param, "A", max(size, 1))
		&& ft_strncmp(param, "C", max(size, 1))
		&& ft_strncmp(param, "L", max(size, 1))
		&& ft_strncmp(param, "sp", max(size, 2))
		&& ft_strncmp(param, "cy", max(size, 2))
		&& ft_strncmp(param, "pl", max(size, 2))
		&& ft_strncmp(param, "co", max(size, 2)))
		return (printf("Invalid element name %s\n", param), 0);
	return (1);
}

int	is_rgb(char *param)
{
	char	**arr;
	int		i;

	if (!param)
		return (0);
	arr = ft_split(param, ',');
	if (!arr)
		return (0);
	i = 0;
	while (arr[++i])
		;
	if (i != 3)
		return (free_arr(arr),
			printf("Error in RGB parameter %s\n", param), 0);
	i = -1;
	while (arr[++i])
	{
		if (!str_is_int(arr[i]))
			return (free_arr(arr),
				printf("Error in RGB paramter %s\n", param), 0);
		if (ft_atoi(arr[i]) > 255)
			return (free_arr(arr),
				printf("RGB out of range %s\n", param), 0);
	}
	return (free_arr(arr), 1);
}

int	is_vector(char *param)
{
	char	**arr;
	int		i;

	if (!param)
		return (0);
	arr = ft_split(param, ',');
	if (!arr)
		return (0);
	i = 0;
	while (arr[++i])
		;
	if (i != 3)
		return (free_arr(arr),
			printf("Error in vector parameter %s\n", param), 0);
	i = -1;
	while (arr[++i])
	{
		if (!str_is_float(arr[i]))
			return (free_arr(arr),
				printf("Error in vector paramter %s\n", param), 0);
		if (ft_atof(arr[i]) < -1.0 || ft_atof(arr[i]) > 1.0)
			return (free_arr(arr),
				printf("Vector out of range %s\n", param));
	}
	return (free_arr(arr), 1);
}
