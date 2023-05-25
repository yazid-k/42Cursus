/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:49 by ekadiri           #+#    #+#             */
/*   Updated: 2023/05/25 16:11:29 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libs/libft/libft.h"
# include "libs/MinilibX/elcapitan/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>

typedef enum e_type
{
	A_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE,
	CONE
}	t_type;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

//Utils
	//1
void	free_arr(void **arr);
void	print_arr(char **arr);
int		str_is_float(char *str);
int		str_is_int(char *str);
int		max(int a, int b);
	//2
int	arr_size(void **arr)


//MLX
t_data	*init_struct(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//Parsing
int		parse_arg(int ac, char **av);
	//Parameters
int		is_light_ratio(char *param);
int		is_coord(char *param);
int		is_name(char *param);
int		is_rgb(char *param);
int		is_vector(char *param);
int		is_fov(char *param);
int		is_measure(char *param);

#endif
