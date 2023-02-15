/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:59:54 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/04 21:19:31 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_rgb(int r, int g, int b)
{
	if (r > 255 || r < 0 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (b + r * (int)pow(16, 4) + g * (int)pow(16, 2));
}

int	get_b(int rgb)
{
	if (rgb == -1)
		return (rgb);
	return (rgb % 256);
}

int	color_iteration(int i, int max, t_data *data)
{
	double	r;
	double	g;
	double	b;
	double	t;

	t = (double)i / (double)max;
	r = 9 * (1 - t) * pow(t, 3.) * 255;
	g = 15 * pow((1 - t), 2.) * pow(t, 2.) * 255;
	b = 8.5 * pow((1 - t), 3.) * t * 255;
	if (data->color == 1)
		return (create_rgb((int)b, (int)g, (int)r));
	if (data->color == 2)
		return (create_rgb((int)r, (int)b, (int)g));
	return (create_rgb((int)r, (int)g, (int)b));
}
