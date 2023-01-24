/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:30:00 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 17:10:29 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	square(void *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	(void)size;
	(void)x;
	(void)y;
	while (++i < 1920)
	{
		j = 0;
		while (++j < 1080)
		{
			if (sqrt(pow(i - 960, 2) + pow(j - 540, 2)) < 50)
				my_mlx_pixel_put(img, i, j, color);
		}
		color += 0x00000006;
		if (color >= 0x00000600)
			color += 0x00000600;
	}
}

int	parse(int ac, char **av)
{
	int		choice;

	if (ac < 2)
	{
		ft_printf("Not enough arguments\n");
		return (0);
	}
	choice = ft_atoi(av[1]);
	if (choice != 1 && choice != 2 && choice != 3)
	{
		ft_printf("Wrong choice\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_data	img;

	(void)ac;
	(void)av;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Test");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	square(&img, 50, 50, 500, 0x00FFFFFF);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);
	mlx_destroy_window(mlx, win);
	return (1);
}
