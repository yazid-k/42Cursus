/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:57:57 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/08 10:58:55 by ekadiri          ###   ########.fr       */
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

int	create_rgb(int r, int g, int b)
{
	if (r > 255 || r < 0 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (b + r * (int)pow(16, 4) + g * (int)pow(16, 2));
}
