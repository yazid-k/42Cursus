/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:21:21 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/05 13:09:41 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	norme(t_complex z)
{
	return (sqrt(pow(z.im, (double)2) + pow(z.re, (double)2)));
}

int	get_color(t_data *data, double x, double y, t_complex c)
{
	int			i;
	t_complex	z;
	t_complex	tmp;

	z.re = x;
	z.im = y;
	i = -1;
	while (++i < data->i_max && norme(z) < 4.)
	{
		tmp.re = z.re;
		tmp.im = z.im;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im + c.re;
		z.im = (2 * tmp.re * tmp.im) + c.im;
	}
	return (i);
}

int	get_color_bs(t_data *data, double x, double y, t_complex c)
{
	int			i;
	t_complex	z;
	t_complex	tmp;

	z.re = x;
	z.im = y;
	i = -1;
	while (++i < data->i_max && norme(z) < 2)
	{
		tmp.re = fabs(z.re);
		tmp.im = fabs(z.im);
		z.re = tmp.re * tmp.re - tmp.im * tmp.im + c.re;
		z.im = (2 * tmp.re * tmp.im) + c.im;
	}
	return (i);
}
