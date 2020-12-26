/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 11:07:31 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/26 18:35:30 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_error(t_vars *vars, int error_flag, int error_point)
{
	if (POINT_DATA_FREE <= error_point)
	{
		free(vars->img.camera);
		free(vars->img.light);
		free_objects(vars->img.objects, vars->img.n_object);
	}
	if (POINT_WIN_FREE <= error_point && !vars->img.save_flag)
		mlx_destroy_window(vars->mlx, vars->win);
	if (POINT_IMAGE_FREE <= error_point)
		free_img_array(vars->img_array, vars->img.n_camera, vars->mlx, !FALSE);
	else if (POINT_DATAS_FREE <= error_point)
		free_img_array(vars->img_array, vars->img.n_camera, vars->mlx, FALSE);
	if (POINT_MLX_FREE <= error_point)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	write_error(error_flag);
	exit(ERROR);
}

void	set_error(char **error)
{
	error[1] = "Failed to read the file";
	error[2] = "The file could not be opened";
	error[3] = "malloc failed";
	error[4] = "Wrong type identifier recognized";
	error[5] = "Duplicate specified type identifier";
	error[6] = "The required type identifier was not found";
	error[7] = "The number of arguments is incorrect";
	error[8] = "Set to \"--save\" to specify the second argument";
	error[9] = "Specify a file with a \".rt\" extension as the first argument";
	error[10] = "Wrong way of writing information of \"resolution\"";
	error[11] = "Wrong way of writing information of \"ambient light\"";
	error[12] = "Wrong way of writing information of \"camera\"";
	error[13] = "Wrong way of writing information of \"light\"";
	error[14] = "Wrong way of writing information of \"sphere\"";
	error[15] = "Wrong way of writing information of \"triangle\"";
	error[16] = "Wrong way of writing information of \"plane\"";
	error[17] = "Wrong way of writing information of \"square\"";
	error[18] = "Wrong way of writing information of \"cylinder\"";
	error[20] = "The screen is too small";
	error[21] = "Failed to create bmp file";
	error[22] = "Failed to write to bmp file";
	error[23] = "The number of digits has exceeded";
	error[24] = "The maximum number of objects has been exceeded";
	error[25] = "An error of mlx has occurred";
}

void	write_error(int flag)
{
	char *error[30];

	flag *= -1;
	set_error(error);
	write(2, "Error\n", 6);
	write(2, error[flag], ft_strlen(error[flag]));
	write(2, "\n", 1);
}

int		exit_destroy(t_vars *vars)
{
	free(vars->img.camera);
	free(vars->img.light);
	free_objects(vars->img.objects, vars->img.n_object);
	free_img_array(vars->img_array, vars->img.n_camera, vars->mlx, !FALSE);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(SUCCESS);
}

int		exit_success(t_vars *vars)
{
	free(vars->img.camera);
	free(vars->img.light);
	free_objects(vars->img.objects, vars->img.n_object);
	if (!vars->img.save_flag)
		mlx_destroy_window(vars->mlx, vars->win);
	free_img_array(vars->img_array, vars->img.n_camera, vars->mlx, !FALSE);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(SUCCESS);
}
