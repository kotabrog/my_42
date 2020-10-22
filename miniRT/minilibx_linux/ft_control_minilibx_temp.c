/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_minilibx_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:37:23 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/17 19:38:13 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		close_window(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int		print_keycode(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
}

int		print_mouse_button_code(int mouse_button_code, t_vars *vars)
{
	printf("%d\n", mouse_button_code);
}

int		print_hook_key(int hook_key, t_vars *vars)
{
	printf("%d\n", hook_key);
}

int		close_window_press_esc_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
}

int		close_window_press_esc(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, close_window_press_esc_hook, vars);
}

int		print_resize_window(t_vars *vars)
{
	mlx_hook(vars->win, ResizeRequest, ResizeRedirectMask, print_hook_key, vars);
}
