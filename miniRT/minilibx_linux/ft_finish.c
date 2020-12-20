/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 11:07:31 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/20 14:32:43 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		free_objects(t_object *objects, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (ft_strchr("t", objects[i].type))
			free(objects[i].points);
		i++;
	}
	free(objects);
}

void	exit_error(t_vars *vars, int error_flag, int error_point)
{
	int i;

	if (POINT_DATA_FREE <= error_point)
	{
		free(vars->img.camera);
		free(vars->img.light);
		free_objects(vars->img.objects, vars->img.n_object);
	}
	if (POINT_DATAS_FREE <= error_point)
	{
		i = vars->img.n_camera;
		while (--i >= 0)
		{
			free(vars->img_array[i].light);
			free_objects(vars->img_array[i].objects, vars->img_array[i].n_object);
		}
		free(vars->img_array);
	}
	write_error(error_flag);
	exit(ERROR);
}

void	write_error(int flag)
{
	char *error[30];

	flag *= -1;
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
	write(2, "Error\n", 6);
	write(2, error[flag], ft_strlen(error[flag]));
	write(2, "\n", 1);
}

int		exit_success(t_vars *vars)
{
	int i;

	free(vars->img.camera);
	free(vars->img.light);
	free_objects(vars->img.objects, vars->img.n_object);
	i = vars->img.n_camera;
	while (--i >= 0)
	{
		free(vars->img_array[i].light);
		free_objects(vars->img_array[i].objects, vars->img_array[i].n_object);
	}
	free(vars->img_array);
	exit(SUCCESS);
}
