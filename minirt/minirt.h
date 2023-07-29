/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:49 by ekadiri           #+#    #+#             */
/*   Updated: 2023/07/29 20:14:24 by ekadiri          ###   ########.fr       */
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
	CYLINDER,
}	t_type;

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}	t_coord;

typedef struct s_ray
{
	t_coord	origin;
	t_coord	direction;
}	t_ray;

typedef struct s_elem
{
	t_type				type;
	float				light;
	int					rgb;
	t_coord				coord;
	t_coord				vector;
	int					fov;
	float				diameter;
	float				height;
	struct s_elem		*next;
}	t_elem;

typedef struct s_matrix
{
	float	m[4][4];
}	t_matrix;

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
	t_matrix		mat;
	t_elem			*cam;
}	t_data;

//Utils
	//1
void		free_arr(char **arr);
void		print_arr(char **arr);
int			str_is_float(char *str);
int			str_is_int(char *str);
int			max(int a, int b);
	//2
int			arr_size(char **arr);
t_coord		coord(float x, float y, float z);
void		print_coord(t_coord c);
t_elem		*get_elem_by_type(t_data *data, t_type type);
	//3
t_ray		ray(t_coord origin, t_coord direction);
void		print_ray(t_ray r);
double		min(double a, double b);
t_matrix	matrix(t_coord a, t_coord b, t_coord c);
	//Color
int			rgb(int r, int g, int b);
int			get_r(int color);
int			get_g(int color);
int			get_b(int color);

//MLX
t_data		*init_struct(char *file);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			close_win(t_data **data);
int			keyhook(int keycode, t_data **data);

//Parsing
int			parse(int ac, char **av);
int			parse_arr(char **arr);
int			parse_elem(int fd);
	//Parameters
int			is_light_ratio(char *param);
int			is_coord(char *param);
int			is_name(char *param);
int			is_rgb(char *param);
int			is_vector(char *param);
int			is_fov(char *param);
int			is_measure(char *param);
	//Elements
int			parse_ambient_light(char **arr);
int			parse_light(char **arr);
int			parse_camera(char **arr);
int			parse_sphere(char **arr);
int			parse_cylinder(char **arr);
int			parse_plane(char **arr);

//Elem
	//List
void		elemclear(t_elem **elem);
void		elemadd_back(t_elem **lst, t_elem *new);
t_elem		*elemlast(t_elem *lst);
t_elem		*elemnew(void);
int			elemsize(t_elem *lst);

	//Struct elem
t_elem		*get_sphere(char **arr);
t_elem		*get_plane(char **arr);
t_elem		*get_cylinder(char **arr);
t_elem		*get_plane(char **arr);
t_elem		*get_ambient_light(char **arr);
t_elem		*get_light(char **arr);
t_elem		*get_camera(char **arr);
t_coord		get_coord_from_string(char *s);
int			get_rgb_from_string(char *s);
t_elem		*get_elem_from_arr(char **arr);
t_elem		*init_elem(char *file);
void		print_elem(t_elem *elem);

//Render
void		render(t_data *data);
int			light(t_coord p, t_data *data, t_elem *elem);

//Math
float		distance(t_coord v1, t_coord v2);
t_coord		norm(t_coord v);
t_coord		vec_add(t_coord v1, t_coord v2);
t_coord		vec_sub(t_coord v1, t_coord v2);
double		vec_dot(t_coord v1, t_coord v2);
t_coord		vec_cross(t_coord v1, t_coord v2);
t_coord		matrix_mult(t_matrix m, t_coord v);
t_matrix	camera_matrix(t_elem *camera);
double		positive_min(double a, double b);

//Hit
t_coord		hit_sphere(t_ray ray, t_elem *sphere);
t_coord		hit_plane(t_ray ray, t_elem *plane);
t_coord		hit(t_ray r, t_elem *elem);

//Normal
t_coord		normal(t_coord hit, t_elem *elem);

#endif
