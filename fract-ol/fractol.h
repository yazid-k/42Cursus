/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:43:39 by ekadiri           #+#    #+#             */
/*   Updated: 2023/02/05 14:33:23 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdlib.h>

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	int			set;
	int			i_max;
	int			color;
	t_complex	z;
	t_complex	mi;
	t_complex	ma;
}				t_data;

//LIBFT
int		ft_printf(const char *s, ...);
int		ft_atoi(const char *str);
double	ft_atof(const char *str);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

//PARSING
int		parse(int ac, char **av);
int		str_isfloat(char *str);
int		str_isnumber(char *str);
int		max(int a, int b);
void	free_tab(char **tab);

//COLOR
int		create_rgb(int r, int g, int b);
int		color_iteration(int i, int max, t_data *data);

//COMPLEX
double	norme(t_complex z);
int		get_color(t_data *data, double x, double y, t_complex c);
int		get_color_bs(t_data *data, double x, double y, t_complex c);

//HOOKS
int		keyboard(int keycode, t_data *data);
int		close_cross(t_data *data);
int		render(int keycode, int x, int y, t_data *data);
int		mouse(int keycode, int x, int y, t_data *data);

//SETS
void	mandelbrot(t_data *data);
void	julia(t_data *data);
void	burning_ship(t_data *data);

//MLX
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data	*init_struct(int max);

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif
