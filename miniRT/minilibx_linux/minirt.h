/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:28:09 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/20 14:33:01 by ksuzuki          ###   ########.fr       */
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

# define MY_DESTROYNOTIFY 17
# define MY_STRUCTURENOTIFYMASK (1L << 17)
# define MY_EXPOSE 12
# define MY_EXPOSUREMASK  (1L << 15)

# define FALSE 0
# define TRUE (!FALSE)
# define ADJUSTMENT_SCREEN 100
# define HEADER_SIZE 54
# define INFO_HEADER_SIZE 40
# define FILE_PERMISSION 0644
# define FILE_OPEN_FLAG (O_RDWR | O_CREAT | O_TRUNC)

# define MAX_FD 255
# define BUFFER_SIZE 1000
# define SUCCESS 0
# define ERROR 1
# define ERROR_GET_LINE -1
# define ERROR_OPEN -2
# define ERROR_MALLOC -3
# define ERROR_TYPE -4
# define ERROR_DUPLICATE -5
# define ERROR_MISSING -6
# define ERROR_ARGC -7
# define ERROR_SAVEFLAG -8
# define ERROR_RT_FILE -9
# define ERROR_RESOLUTION -10
# define ERROR_AMBIENT_LIGHT -11
# define ERROR_CAMERA -12
# define ERROR_LIGHT -13
# define ERROR_SPHERE -14
# define ERROR_TRIANGLE -15
# define ERROR_PLANE -16
# define ERROR_SQUARE -17
# define ERROR_CYLINDER -18
# define ERROR_SCREEN_SIZE -20
# define ERROR_CREATE_FILE -21
# define ERROR_WRITE_FILE -22
# define ERROR_OVER -23

# define POINT_NOT_FREE 0
# define POINT_DATA_FREE 1
# define POINT_DATAS_FREE 2

# define TYPE_ERROR 'e'
# define TYPE_LIGHT 'l'
# define TYPE_SPHERE 's'
# define TYPE_TRIANGLE 't'
# define TYPE_PLANE 'p'
# define TYPE_SQUARE 'q'
# define TYPE_CYLINDER 'c'
# define TYPE_TUBE 'u'
# define TYPE_CIRCLE 'i'

# define KEY_ESC 65307
# define KEY_ZERO 48
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364


typedef struct s_vec {
	double	x;
	double	y;
	double	z;
	// int		x_int;
	// int		y_int;
	// int		z_int;
}				t_vec;

typedef struct s_object {
	// int		x;
	// int		y;
	// int		z;
	t_vec	vec;
	t_vec	no_vec;
	t_vec	*points;
	// int		width;
	double	height;//cylinder, tube
	// int		depth;
	double	r;//sphere, cylinder, circle, tube
	double	size;//square
	// int		len;
	int		h_fov;//camera
	double	ratio;//light
	// double	theta;
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
	// double		ep;
	int			front_ob_i;
	t_vec		front_ob_point;
	// int			flag[2];
	int			save_flag;
}				t_data;

typedef struct	s_type {
	int		first;
	int		second;
	int		resolution;
	int		ambient;
}				t_type;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	t_data	*img_array;
}				t_vars;

int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *s, int c);
int			ft_strchr_n(const char *s, int c);
char		*ft_strchr_ex(const char *s, int c, ssize_t *len, int *flag);
int			ft_get_ndigits(int n);
char		*ft_strrchr(const char *s, int c);
t_vec		vec_set(double x, double y, double z);
t_vec		vec_add(t_vec *a, t_vec *b);
void		vec_angle_add(t_vec *dst, t_vec *v);
void		vec_angle_minus(t_vec *dst, t_vec *v);
// t_vec		vec_product(t_vec a, t_vec b);
t_vec		vec_product_scaler(t_vec *v, double a);
// t_vec		vec_round(t_vec a);
double		vec_inner_product(t_vec *a, t_vec *b);
void		vec_outer_product(t_vec *v, t_vec *a, t_vec *b);
double		vec_squared_norm(t_vec *a);
// double		vec_norm(t_vec a);
void		vec_atob(t_vec *dst, t_vec *a, t_vec *b);
int			vec_equal(t_vec *a, t_vec *b);
int			vec_check_nonzero(t_vec *v);
// t_vec		vec_norm_vec(t_vec a);
void		vec_set_inplace(t_vec *v, double x, double y, double z);
void		vec_add_inplace(t_vec *dst, t_vec *v);
void		vec_product_scaler_inplace(t_vec *dst, double a);
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
// int			get_opposite_trgb(int trgb);
// int			add_double_transparency(double t, int trgb);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		adjust_screen_size(t_vars *vars);
void		set_all_mlx_hook(t_vars *vars);
void		set_img(t_vars *vars, t_data *img, t_data **img_array, void **mlx);
int			exit_success(t_vars *vars);
double		sphere_discriminant(t_vec *start, t_vec *center, t_vec *direction, double r);
double		sphere_solution(t_vec *start, t_vec *center, t_vec *direction, double d);
int			sphere_block(t_object *ob, t_vec *l_point);
t_vec		sphere_normal(t_vec *point, t_object *ob);
double		calc_determinant(t_vec *a, t_vec *b, t_vec *c);
void		rotation_matrix(t_vec *angle, t_vec *x);
void		rotation_inverse_matrix(t_vec *angle, t_vec *x);
double		triangle_discriminant(t_vec *start, t_vec *direction, t_object *ob);
t_vec		triangle_normal(t_object *ob, t_vec *point);
double		plane_discriminant(t_vec *start, t_vec *direction, t_object *ob);
t_vec		plane_normal(t_vec *n_vec, t_vec *point);
double		tube_discriminant(t_vec start, t_vec direction, t_object *ob);
int			tube_block(t_object *ob, t_vec *l_point, t_vec *point);
t_vec		tube_normal(t_vec point, t_object *ob);
double		circle_discriminant(t_vec start, t_vec dir, t_object *ob);
t_vec		circle_normal(t_object *ob, t_vec *point);
int			set_int(char **s, int *flag);
double		set_double(char **s, int *flag);
int			set_color(char **s, int *flag);
void		set_vec(t_vec *v, char **s, int *flag, int error_num);
void		set_object(t_object **ob, int *n_ob, int *flag);
void		set_resolution(t_data *img, char *s, int *flag, t_type *type_flag);
void		set_ambient_light(t_data *img, char *s, int *flag, t_type *type_flag);
void		set_camera(t_data *img, char *s, int *flag);
void		set_light(t_data *img, char *s, int *flag);
void		set_screen(t_data *img);
void		set_sphere(t_data *img, char *s, int *flag);
void		set_triangle(t_data *img, char *s, int *flag);
void		set_plane(t_data *img, char *s, int *flag);
void		set_square(t_data *img, char *s, int *flag);
void		set_cylinder(t_data *img, char *s, int *flag);
t_object	triangle_set(t_vec *p0, t_vec *p1, t_vec *p2, int c);
t_object	circle_set(t_vec center, t_vec n_vec, double r, int color);
int			ft_isin_double(double a, double b, double c);
// int			ft_isin_double_vec_nequal(double a, t_vec *b, double c);
int			ft_isin_int(int a, int b, int c);
int			ft_isin_int_nequal(int a, int b, int c);
int			ft_isin_double_vec(double a, t_vec *b, double c);
int			ft_isdigit(int c);
int			ft_isspace(int c);
void		ft_advance_isspace(char **s);
int			is_rt_file(const char *file);
void		check_arg(t_vars *vars, int argc, char **argv);
void		object_shift(t_data *img);
void		object_rotaion(t_data *img);
// int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_strcpy(char *p, char const *s, size_t n);
void		write_error(int flag);
void		exit_error(t_vars *vars, int error_flag, int error_point);
void		export_bmp(t_vars *vars, t_data *img, char *file_name, int camera_num);
double		calc_discriminant(t_vec *start, t_vec *direction, t_object *ob);
int			is_true_discriminant(t_object *ob, double d);
double		calc_solution(t_vec *start, t_vec *direction, t_object *ob, double d);
t_vec		calc_normal(t_vec *point, t_object *ob, t_data *img);
int			calc_self_block(t_data *img, t_vec *l_point, t_object *ob);
int			choice_object(t_data *img, int point[2]);
int			calc_shadow(t_data *img);

#endif
