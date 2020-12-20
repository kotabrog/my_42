/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_minilibx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 22:44:49 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/19 21:04:16 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	adjust_screen_size(t_vars *vars)
{
	int x;
	int y;

	mlx_get_screen_size(vars->mlx, &x, &y);
	if (x - ADJUSTMENT_SCREEN < vars->img.x)
		vars->img.x = x - ADJUSTMENT_SCREEN;
	if (y - ADJUSTMENT_SCREEN < vars->img.y)
		vars->img.y = y - ADJUSTMENT_SCREEN;
	if (vars->img.x <= 0 || vars->img.y <= 0)
		exit_error(vars, ERROR_SCREEN_SIZE, POINT_DATA_FREE);
}

int		control_key_code(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit_success(vars);
	}
	if (keycode == KEY_RIGHT || keycode == KEY_DOWN)
		keycode = (vars->img.now_camera + 1) % vars->img.n_camera + KEY_ZERO + 1;
	if (keycode == KEY_LEFT || keycode == KEY_UP)
		keycode = ((vars->img.now_camera == 0 ? vars->img.n_camera - 1 : vars->img.now_camera - 1))\
				+ KEY_ZERO + 1;
	if (KEY_ZERO < keycode && keycode < KEY_ZERO + 10 && vars->img.n_camera >= keycode - KEY_ZERO)
	{
		vars->img.now_camera = keycode - KEY_ZERO - 1;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_array[vars->img.now_camera].img, 0, 0);
	}
}

int		put_img_when_resized(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, \
							vars->win, \
							vars->img_array[vars->img.now_camera].img, \
							0, 0);
}

void	set_all_mlx_hook(t_vars *vars)
{
		mlx_key_hook(vars->win, control_key_code, vars);
		mlx_hook(vars->win, MY_DESTROYNOTIFY, MY_STRUCTURENOTIFYMASK, exit_success, vars);
		mlx_hook(vars->win, MY_EXPOSE, MY_EXPOSUREMASK, put_img_when_resized, vars);
}
