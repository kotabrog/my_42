/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:17:48 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/20 10:21:58 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_resolution(t_data *img, char *s, int *flag)
{
	if (img->flag[0])
	{
		*flag = ERROR_DUPLICATE;
		return ;
	}
	img->flag[0] = 1;
	ft_advance_isspace(&s);
	img->x = set_int(&s);
	ft_advance_isspace(&s);
	img->y = set_int(&s);
	ft_advance_isspace(&s);
	if (img->x == 0 || img->y == 0 || *s != 0)
		*flag = ERROR_RESOLUTION;
}

void	set_ambient_light(t_data *img, char *s, int *flag)
{
	if (img->flag[1])
	{
		*flag = ERROR_DUPLICATE;
		return ;
	}
	img->flag[1] = 1;
	ft_advance_isspace(&s);
	img->ambient_light_ratio = set_double(&s);
	ft_advance_isspace(&s);
	img->ambient_light = set_color(&s);
	ft_advance_isspace(&s);
	if (img->ambient_light == -1 || \
		!ft_isin_double(0, img->ambient_light_ratio, 1) || \
		*s != 0)
		*flag = ERROR_AMBIENT_LIGHT;
}

void	set_camera(t_data *img, char *s, int *flag)
{
	t_object *ob;

	set_object(&(img->camera), &(img->n_camera));
	if (img->n_camera <= 0)
	{
		*flag = ERROR_MALLOC;
		return ;
	}
	ob = &(img->camera[img->n_camera - 1]);
	ft_advance_isspace(&s);
	ob->vec = set_vec(&s);
	ft_advance_isspace(&s);
	ob->no_vec = set_vec(&s);
	ft_advance_isspace(&s);
	if (!ft_isdigit(*s))
		*flag = ERROR_CAMERA;
	ob->h_fov = set_int(&s);
	ft_advance_isspace(&s);
	if (ob->vec.x_int || ob->no_vec.x_int || \
		!ft_isin_double_vec(-1, ob->no_vec, 1) || \
		!ft_isin_int(0, ob->h_fov, 180) || *s != 0)
		*flag = ERROR_CAMERA;
}

void	set_light(t_data *img, char *s, int *flag)
{
	t_object *ob;
	
	set_object(&(img->light), &(img->n_light));
	if (img->n_light <= 0)
	{
		*flag = ERROR_MALLOC;
		return ;
	}
	ob = &(img->light[img->n_light - 1]);
	ft_advance_isspace(&s);
	ob->vec = set_vec(&s);
	ft_advance_isspace(&s);
	ob->ratio = set_double(&s);
	ft_advance_isspace(&s);
	ob->color = set_color(&s);
	ft_advance_isspace(&s);
	if (ob->color == -1 || \
		!ft_isin_double(0, ob->ratio, 1) || ob->vec.x_int || *s != 0)
		*flag = ERROR_LIGHT;
}

void	set_screen(t_data *img)
{
	double fov;

	fov = img->camera[img->now_camera].h_fov;
	img->screen.x = -(double)img->x / 2 + 0.5;
	img->screen.y = -(double)img->y / 2 + 0.5;
	img->screen.z = ((double)img->x / 2) * \
					tan((0.5 - fov / 360) * M_PI);
}
