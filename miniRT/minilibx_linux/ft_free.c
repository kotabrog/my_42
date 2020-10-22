/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 11:07:31 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/20 12:01:27 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		free_objects(t_object *objects, int n)
{
	int i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (i < n)
	{
		if (ft_strchr_n("t", objects[i].type) >= 0)
			free(objects[i].points);
		i++;
	}
	free(objects);
}

void	free_all(t_data *img)
{
	free(img->camera);
	free(img->light);
	free_objects(img->objects, img->n_object);
}
