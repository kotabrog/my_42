/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:50:28 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/25 23:16:11 by ksuzuki          ###   ########.fr       */
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

void		free_img_array(t_data *img_array, int n, void *mlx, int flag)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(img_array[i].light);
		free_objects(img_array[i].objects, img_array[i].n_object);
		if (flag || i < n - 1)
			mlx_destroy_image(mlx, img_array[i].img);
		i++;
	}
	free(img_array);
}
