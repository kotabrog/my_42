/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:40:33 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/20 14:28:06 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	img->save_flag = FALSE;
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

void	all_put_object(t_vars *vars, char **argv)
{
	int i;

	write(1, "processing...\n", 14);
	put_objects(&(vars->img_array[0]));
	vars->img.now_camera = 0;
	if (vars->img.save_flag)
		export_bmp(vars, &(vars->img_array[0]), argv[1], 1);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_array[0].img, 0, 0);
	i = 1;
	while (i < vars->img.n_camera)
	{
		put_objects(&(vars->img_array[i++]));
		if (vars->img.save_flag)
			export_bmp(vars, &(vars->img_array[0]), argv[1], i);
	}
	if (vars->img.save_flag)
	{
		write(1, "finish\n", 7);
		exit_success(vars);
	}
	write(1, "Accept input\n", 13);
}

int		main(int argc, char **argv)
{
	t_vars		vars;
	int			flag;

	img_init(&(vars.img));
	vars.img_array = NULL;
	check_arg(&(vars), argc, argv);
	vars.mlx = mlx_init();
	adjust_screen_size(&vars);
	if (!vars.img.save_flag)
		vars.win = mlx_new_window(vars.mlx, vars.img.x, vars.img.y, "Hello world!");
	set_img(&vars, &(vars.img), &(vars.img_array), &(vars.mlx));
	all_put_object(&vars, argv);
	set_all_mlx_hook(&vars);
	mlx_loop(vars.mlx);
}
