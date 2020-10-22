/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:28:09 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/10/18 22:51:05 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <X11/Xlib.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include "./minilibx-linux/mlx.h"

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# define MAX_FD 255
# define BUFFER_SIZE 1000
# define ERROR_GET_LINE -1
# define ERROR_OPEN -2
# define ERROR_MALLOC -3
# define ERROR_TYPE -4
# define ERROR_DUPLICATE -5
# define ERROR_MISSING -6
# define ERROR_ARGC -7
# define ERROR_SAVEFLAG -8
# define ERROR_RESOLUTION -10
# define ERROR_AMBIENT_LIGHT -11
# define ERROR_CAMERA -12
# define ERROR_LIGHT -13
# define ERROR_SPHERE -14
# define ERROR_TRIANGLE -15
# define ERROR_PLANE -16
# define ERROR_SQUARE -17
# define ERROR_CYLINDER -18

# define TYPE_ERROR 'e'
# define TYPE_SPHERE 's'
# define TYPE_TRIANGLE 't'
# define TYPE_PLANE 'p'
# define TYPE_SQUARE 'q'
# define TYPE_CYLINDER 'c'
# define TYPE_TUBE 'u'

typedef struct s_vec {
	double	x;
	double	y;
	double	z;
	int		x_int;
	int		y_int;
	int		z_int;
}				t_vec;

typedef struct s_object {
	int		x;
	int		y;
	int		z;
	t_vec	vec;
	t_vec	no_vec;
	t_vec	*points;
	int		width;
	int		height;
	int		depth;
	double	r;
	double	size;
	int		len;
	int		h_fov;
	double	ratio;
	double	theta;
	int		color;
	char	type;
}				t_object;
	
typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	int			background;
	int			ambient_light;
	double		ambient_light_ratio;
	t_object	*camera;
	int			n_camera;
	int			now_camera;
	t_object	*light;
	int			n_light;
	t_object	*objects;
	int			n_object;
	t_vec		screen;
	double		ep;
	int			front_ob_i;
	t_vec		front_ob_point;
	int			flag[2];
	int			save_flag;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *s, int c);
int			ft_strchr_n(const char *s, int c);
char		*ft_strchr_ex(const char *s, int c, ssize_t	 *len, int *flag);
char		*ft_strndup(const char *s, ssize_t n);
char		*ft_strjoin_ex(char *s1, char *s2, ssize_t n1, ssize_t n2);
t_vec		vec_set(double x, double y, double z);
t_vec		vec_add(t_vec a, t_vec b);
t_vec		vec_product(t_vec a, t_vec b);
t_vec		vec_product_scaler(t_vec v, double a);
t_vec		vec_round(t_vec a);
double		vec_inner_product(t_vec a, t_vec b);
t_vec		vec_outer_product(t_vec a, t_vec b);
double		vec_squared_norm(t_vec a);
double		vec_norm(t_vec a);
t_vec		vec_atob(t_vec a, t_vec b);
int			vec_equal(t_vec a, t_vec b);
int			vec_check_nonzero(t_vec v);
int			trgb_to_t(int trgb);
int			trgb_to_r(int trgb);
int			trgb_to_g(int trgb);
int			trgb_to_b(int trgb);
int			trgb_to_t_int(int trgb);
int			trgb_to_r_int(int trgb);
int			trgb_to_g_int(int trgb);
int			create_trgb(int t, int r, int g, int b);
int			color_product(double ratio, int trgb);
int			color_max(int trgb1, int trgb2);
int			color_sum(int trgb1, int trgb2);
int			get_opposite_trgb(int trgb);
int			add_double_transparency(double t, int trgb);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		sphere_discriminant(t_vec start, t_vec center, t_vec direction, double r);
double		sphere_solution(t_vec start, t_vec center, t_vec direction, double d);
int			sphere_block(t_object ob, t_vec l_point);
t_vec		sphere_normal(t_vec point, t_object ob);
double		calc_determinant(t_vec a, t_vec b, t_vec c);
t_vec		matrix_product_vec(t_vec m[3], t_vec v);
t_vec		rotation_one_axis(double angle, t_vec x, int axis);
t_vec		rotation_matrix(t_vec angle, t_vec x);
t_vec		rotation_inverse_matrix(t_vec angle, t_vec x);
double		triangle_discriminant(t_vec start, t_vec direction, t_object ob);
t_vec		triangle_normal(t_object ob, t_vec point);
double		plane_discriminant(t_vec start, t_vec direction, t_object ob);
t_vec		plane_normal(t_vec n_vec, t_vec point);
double		tube_discriminant(t_vec start, t_vec direction, t_object ob);
int			set_int(char **s);
double		set_double(char **s);
int			set_color(char **s);
t_vec		set_vec(char **s);
void		set_object(t_object **ob, int *n_ob);
void		set_resolution(t_data *img, char *s, int *flag);
void		set_ambient_light(t_data *img, char *s, int *flag);
void		set_camera(t_data *img, char *s, int *flag);
void		set_light(t_data *img, char *s, int *flag);
void		set_screen(t_data *img);
void		set_sphere(t_data *img, char *s, int *flag);
void		set_triangle(t_data *img, char *s, int *flag);
void		set_plane(t_data *img, char *s, int *flag);
void		set_square(t_data *img, char *s, int *flag);
void		set_cylinder(t_data *img, char *s, int *flag);
t_object	triangle_set(t_vec p0, t_vec p1, t_vec p2, int c);
int			ft_isin_double(double a, double b, double c);
int			ft_isin_double_nequal(double a, double b, double c);
int			ft_isin_int(int a, int b, int c);
int			ft_isin_int_nequal(int a, int b, int c);
int			ft_isin_double_vec(double a, t_vec b, double c);
int			ft_isdigit(int c);
int			ft_isspace(int c);
void		ft_advance_isspace(char **s);
int			get_object_data(t_data *img, char *argv);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
ssize_t		ft_strlen(const char *s);
void		free_all(t_data *img);

#endif
