/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:51:35 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/19 21:24:36 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		copy_objects(t_object *dist, t_object *src, int *n)
{
	int i;
	int j;

	i = 0;
	while (i < *n)
	{
		dist[i] = src[i];
		char s[3];
		s[0] = dist[i].type;
		s[1] = '\n';
		if (ft_strchr("t", dist[i].type))
		{
			if (!(dist[i].points = (t_vec *)malloc(sizeof(t_vec) * 3)))
			{
				*n = i;
				return (ERROR_MALLOC);
			}
			j = -1;
			while (++j < 3)
				dist[i].points[j] = src[i].points[j];
		}
		i++;
	}
	return (SUCCESS);
}

int		copy_data(t_data *dist, t_data *src)
{
	*dist = *src;
	if (!(dist->light = (t_object *)malloc(sizeof(t_object) * dist->n_light)))
	{
		dist->n_object = 0;
		return (ERROR_MALLOC);
	}
	copy_objects(dist->light, src->light, &(dist->n_light));
	if (!(dist->objects = (t_object *)malloc(sizeof(t_object) * dist->n_object)))
		return (ERROR_MALLOC);
	if (copy_objects(dist->objects, src->objects, &(src->n_object)))
		return (ERROR_MALLOC);
	return (SUCCESS);
}

void	set_img(t_vars *vars, t_data *img, t_data **img_array, void **mlx)
{
	int i;

	i = 0;
	if (!(*img_array = (t_data *)malloc(sizeof(t_data) * img->n_camera)))
		exit_error(vars, ERROR_MALLOC, POINT_DATA_FREE);
	while (i < img->n_camera)
	{
		if (copy_data(&((*img_array)[i]), img))
		{
			img->n_camera = i + 1;
			exit_error(vars, ERROR_MALLOC, POINT_DATAS_FREE);
		}
		(*img_array)[i].now_camera = i;
		(*img_array)[i].img = mlx_new_image(*mlx, (*img_array)[i].x, (*img_array)[i].y);
		(*img_array)[i].addr = mlx_get_data_addr((*img_array)[i].img, \
				&((*img_array)[i].bits_per_pixel), &((*img_array)[i].line_length),\
				&((*img_array)[i].endian));
		set_screen(&((*img_array)[i]));
		++i;
	}
}
