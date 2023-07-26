/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:25:04 by ekadiri           #+#    #+#             */
/*   Updated: 2023/07/26 16:25:55 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	rgb(int r, int g, int b)
{
	if (r > 255 || r < 0 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (b + r * (int)pow(16, 4) + g * (int)pow(16, 2));
}

int	get_r(int color)
{
	return (color >> 16);
}

int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}
