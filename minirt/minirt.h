/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:49 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/08 13:30:59 by ekadiri          ###   ########.fr       */
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


typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
}	t_coords;

typedef struct s_elem
{
	t_type				type;
	float				light;
	int					rgb;
	t_coords			coord;
	t_coords			vector;
	int					fov;
	float				diameter;
	float				height;
	struct s_elem		*next;
}	t_elem;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_elem			*elem;
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
int		create_rgb(int r, int g, int b);


//MLX
t_data	*init_struct(char *file);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	clear_all(t_data *data);

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
int		parse_ambient_light(char **arr);
int		parse_light(char **arr);
int		parse_camera(char **arr);
int		parse_sphere(char **arr);
int		parse_cylinder(char **arr);
int		parse_plane(char **arr);
int		parse_cone(char **arr);

//Elem
	//List
void	elemclear(t_elem **elem);
void	elemadd_back(t_elem **lst, t_elem *new);
t_elem	*elemlast(t_elem *lst);
t_elem	*elemnew(void);
int		elemsize(t_elem *lst);

	//Struct elem
t_elem	*get_sphere(char **arr);
t_elem	*get_plane(char **arr);
t_elem	*get_cylinder(char **arr);
t_elem	*get_plane(char **arr);
t_elem	*get_cone(char **arr);
t_elem	*get_ambient_light(char **arr);
t_elem	*get_light(char **arr);
t_elem	*get_camera(char **arr);
t_coords	get_coords_from_string(char *s);
int		get_rgb_from_string(char *s);
t_elem	*get_elem_from_arr(char **arr);
t_elem	*init_elem(char *file);
void	print_elem(t_elem *elem);

//Render
void	render(t_data *data);
#endif
