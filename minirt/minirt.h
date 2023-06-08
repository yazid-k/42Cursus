/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:56:49 by ekadiri           #+#    #+#             */
/*   Updated: 2023/06/08 13:43:03 by ekadiri          ###   ########.fr       */
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


typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}	t_coord;

typedef struct s_elem
{
	t_type				type;
	float				light;
	int					rgb;
	t_coord			coord;
	t_coord			vector;
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
int		rgb(int r, int g, int b);
t_coord	coord(float x, float y, float z);
void		print_coord(t_coord c);


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
t_coord	get_coord_from_string(char *s);
int		get_rgb_from_string(char *s);
t_elem	*get_elem_from_arr(char **arr);
t_elem	*init_elem(char *file);
void	print_elem(t_elem *elem);

//Render
void	render(t_data *data);

//Math
float	distance(t_coord v1, t_coord v2);

#endif
