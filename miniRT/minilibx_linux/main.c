/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:40:33 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/10/18 22:52:28 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calc_discriminant(t_vec start, t_vec direction, t_object ob)
{
	double d;

	if (ob.type == TYPE_SPHERE)
		d = sphere_discriminant(start, ob.vec, direction, ob.r);
	if (ob.type == TYPE_TRIANGLE)
		d = triangle_discriminant(start, direction, ob);
	if (ob.type == TYPE_PLANE)
		d = plane_discriminant(start, direction, ob);
	if (ob.type == TYPE_TUBE)
		d = tube_discriminant(start, direction, ob);
	return (d);
}

int		is_true_discriminant(t_object ob, double d)
{
	int	flag;

	if (ob.type == TYPE_SPHERE)
		flag = (d >= 0);
	if (ob.type == TYPE_TRIANGLE)
		flag = isfinite(d);
	if (ob.type == TYPE_PLANE)
		flag = (d >= 0 && isfinite(d));
	if (ob.type == TYPE_TUBE)
		flag = (d <= ob.r);
	return (flag);
}

double	calc_solution(t_vec start, t_vec direction, t_object ob, double d)
{
	double solution;

	if (ob.type == TYPE_SPHERE)
		solution = sphere_solution(start, ob.vec, direction, d);
	if (ob.type == TYPE_TRIANGLE)
		solution = d;
	if (ob.type == TYPE_PLANE)
		solution = d;
	return (solution);
}

int		choice_object(t_data *img, int point[2])
{
	int i;
	double	d;
	double	front_d;
	t_vec	direction;

	i = 0;
	front_d = -1;
	direction = vec_add(img->screen, vec_set(point[0], point[1], 0));
	while (i < img->n_object)
	{
		d = calc_discriminant(vec_set(0, 0, 0), direction, img->objects[i]);
		if (is_true_discriminant(img->objects[i], d))
		{
			d = calc_solution(vec_set(0, 0, 0), direction, img->objects[i], d);
			if (0 < d && (d < front_d || front_d == -1))
			{
				front_d = d;
				img->front_ob_i = i;
				img->front_ob_point = vec_product_scaler(direction, d);
			}
		}
		i++;
	}
	return (front_d == -1 ? 0 : 1);
}

t_vec	calc_normal(t_vec point, t_object ob, t_data *img, t_vec l_point)
{
	t_vec	vec;

	if (ob.type == TYPE_SPHERE)
		vec = sphere_normal(point, ob);
	if (ob.type == TYPE_TRIANGLE)
		vec = triangle_normal(ob, point);
	if (ob.type == TYPE_PLANE)
		vec = plane_normal(ob.no_vec, point);
	return (vec);
}

void	calc_cos(t_data *img, t_vec l_point, double cos_arr[2])
{
	t_vec	vec;
	double	temp;
	t_vec	normal_v;
	t_vec	ob_point;

	ob_point = img->front_ob_point;
	normal_v = calc_normal(ob_point, img->objects[img->front_ob_i], img, l_point);
	vec = vec_atob(l_point, ob_point);
	temp = -1 * vec_inner_product(vec, normal_v);
	cos_arr[0] = temp / sqrt(vec_squared_norm(vec) * vec_squared_norm(normal_v)) + 1e-9;
	if (cos_arr[0] < 0)
		cos_arr[0] = 0;
	temp = temp * 2 / vec_squared_norm(normal_v);
	vec = vec_add(vec_product_scaler(normal_v, temp), vec);
	cos_arr[1] = -1 * vec_inner_product(vec, ob_point);
	cos_arr[1] /= sqrt(vec_squared_norm(vec) * vec_squared_norm(ob_point)) + 1e-9;
	cos_arr[1] = (cos_arr[1] < 0 ? 0 : pow(cos_arr[1], 10));
}

int		calc_color(t_data *img, double cos_arr[2], t_object light)
{
	int	color;
	int	temp;

	color = color_product(cos_arr[0] * light.ratio,\
						img->objects[img->front_ob_i].color);
	temp = color_product(cos_arr[1] * light.ratio, light.color);
	color = color_max(color, temp);
	// temp = color_product(img->ambient_light_ratio, img->ambient_light);
	// color = color_max(color, temp);
	return (color);
}

int		calc_self_block(t_data *img, t_vec l_point, t_object ob)
{
	if (ob.type == TYPE_SPHERE)
		return (sphere_block(ob, l_point));
	return (0);
}

int		calc_light_block(double front_d, t_vec direction, t_vec l_point, t_data *img)
{
	int		i;
	double	d;

	if (calc_self_block(img, l_point, img->objects[img->front_ob_i]))
		return (1);
	i = 0;
	while (i < img->n_object)
	{
		if (i != img->front_ob_i)
		{
			d = calc_discriminant(l_point, direction, img->objects[i]);
			if (is_true_discriminant(img->objects[i], d))
			{
				d = calc_solution(l_point, direction, img->objects[i], d);
				if (d < front_d)
					break ;
			}
		}
		i++;
	}
	return (i != img->n_object ? 1 : 0);
}

int		calc_shadow(t_data *img)
{
	double	cos_arr[2];
	t_vec	direction;
	double	front_d;
	int		color;
	int		i;

	color = color_product(img->ambient_light_ratio, img->ambient_light);
	i = 0;
	while (i < img->n_light)
	{
		direction = vec_atob(img->light[i].vec, img->front_ob_point);
		front_d = calc_discriminant(img->light[i].vec, direction, img->objects[img->front_ob_i]);
		front_d = calc_solution(img->light[i].vec, direction, img->objects[img->front_ob_i], front_d);
		if (!calc_light_block(front_d, direction, img->light[i].vec, img))
		{
			calc_cos(img, img->light[i].vec, cos_arr);
			color = color_sum(calc_color(img, cos_arr, img->light[i]), color);
		}
		i++;
	}
	return (color);
}


void	put_objects(t_data *img)
{
	int		point[2];

	point[0] = 0;
	while (point[0] < img->x)
	{
		point[1] = 0;
		while (point[1] < img->y)
		{
			if (!choice_object(img, point))
				my_mlx_pixel_put(img, point[0], point[1], img->background);
			else
				my_mlx_pixel_put(img, point[0], point[1], calc_shadow(img));
			point[1]++;
		}
		point[0]++;
	}
}

void	img_init(t_data *img)
{
	img->background = create_trgb(0, 134, 209, 238);
	img->ambient_light = 0;
	img->ambient_light_ratio = 0;
	img->camera = NULL;
	img->n_camera = 0;
	img->now_camera = 0;
	img->light = NULL;
	img->n_light = 0;
	img->objects = NULL;
	img->n_object = 0;
	img->flag[0] = 0;
	img->flag[1] = 0;
	img->save_flag = 0;
}

int		check_arg(t_data *img, int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 10) != 0)
			return (ERROR_SAVEFLAG);
		img->save_flag = 1;
	}
	if (argc != 2 && argc != 3)
		return (ERROR_ARGC);
	return (0);
}

void	write_error(int flag)
{
	char *error[20];

	error[1] = "1";
	error[2] = "2";
	error[3] = "3";
	error[4] = "4";
	error[5] = "5";
	error[6] = "6";
	error[7] = "7";
	error[8] = "8";
	error[10] = "10";
	error[11] = "11";
	error[12] = "12";
	error[13] = "13";
	error[14] = "14";
	error[15] = "15";
	write(2, "Error\n", 6);
	write(2, error[-1 * flag], ft_strlen(error[-1 * flag]));
	write(2, "\n", 1);
}

int		main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_object	object;
	int			flag;

	img_init(&img);
	if ((flag = check_arg(&img, argc, argv)) == 0)
		flag = get_object_data(&img, argv[1]);
	if (flag == 0)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, img.x, img.y, "Hello world!");

		img.img = mlx_new_image(mlx, img.x, img.y);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

		printf("n_object: %d\n", img.n_object);

		set_screen(&img);
		put_objects(&img);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
	free_all(&img);
	if (flag < 0)
		write_error(flag);
}
