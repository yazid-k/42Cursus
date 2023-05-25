/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:49 by ekadiri           #+#    #+#             */
/*   Updated: 2023/05/25 17:17:11 by ekadiri          ###   ########.fr       */
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
void	free_arr(char **arr);
void	print_arr(char **arr);
int		str_is_float(char *str);
int		str_is_int(char *str);
int		max(int a, int b);
	//2
int		arr_size(char **arr);


//MLX
t_data	*init_struct(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//Parsing
int		parse(int ac, char **av);
int		parse_arr(char **arr);
int		parse_elem(int fd);
	//Parameters
int		is_light_ratio(char *param);
int		is_coord(char *param);
int		is_name(char *param);
int		is_rgb(char *param);
int		is_vector(char *param);
int		is_fov(char *param);
int		is_measure(char *param);
	//Elements
int	parse_ambient_light(char **arr);
int	parse_light(char **arr);
int	parse_camera(char **arr);
int	parse_sphere(char **arr);
int	parse_cylinder(char **arr);
int	parse_plane(char **arr);
int	parse_cone(char **arr);

#endif
