/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:17:48 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/26 01:37:36 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_resolution(t_data *img, char *s, int *flag, t_type *type_flag)
{
	if (type_flag->resolution)
	{
		*flag = ERROR_DUPLICATE;
		return ;
	}
	type_flag->resolution = !FALSE;
	ft_advance_isspace(&s);
	img->x = set_int(&s, flag);
	ft_advance_isspace(&s);
	img->y = set_int(&s, flag);
	ft_advance_isspace(&s);
	if (*flag >= 0 && (img->x == 0 || img->y == 0 || *s != 0 || \
								img->x > 10000 || img->y > 10000))
		*flag = ERROR_RESOLUTION;
}

void	set_ambient_light(t_data *img, char *s, int *flag, t_type *type_flag)
{
	if (type_flag->ambient)
	{
		*flag = ERROR_DUPLICATE;
		return ;
	}
	type_flag->ambient = !FALSE;
	ft_advance_isspace(&s);
	img->ambient_light_ratio = set_double(&s, flag);
	ft_advance_isspace(&s);
	img->ambient_light = set_color(&s, flag);
	ft_advance_isspace(&s);
	if (*flag >= 0 && (img->ambient_light == -1 || \
		!ft_isin_double(0, img->ambient_light_ratio, 1) || \
		*s != 0))
		*flag = ERROR_AMBIENT_LIGHT;
}

void	set_camera(t_data *img, char *s, int *flag)
{
	t_object *ob;

	set_object(&(img->camera), &(img->n_camera), flag);
	if (*flag < 0)
		return ;
	ob = &(img->camera[img->n_camera - 1]);
	ft_advance_isspace(&s);
	set_vec(&(ob->vec), &s, flag, ERROR_CAMERA);
	ft_advance_isspace(&s);
	set_vec(&(ob->no_vec), &s, flag, ERROR_CAMERA);
	ft_advance_isspace(&s);
	if (!ft_isdigit(*s))
		*flag = ERROR_CAMERA;
	ob->h_fov = set_int(&s, flag);
	ft_advance_isspace(&s);
	if (*flag >= 0 && (!ft_isin_double_vec(-1, &(ob->no_vec), 1) || \
		!ft_isin_int_nequal(0, ob->h_fov, 180) || *s != 0))
		*flag = ERROR_CAMERA;
	if (*flag >= 0)
		vec_product_scaler_inplace(&(ob->no_vec), M_PI);
}

void	set_light(t_data *img, char *s, int *flag)
{
	t_object *ob;

	set_object(&(img->light), &(img->n_light), flag);
	if (*flag < 0)
		return ;
	ob = &(img->light[img->n_light - 1]);
	ob->type = TYPE_LIGHT;
	ft_advance_isspace(&s);
	set_vec(&(ob->vec), &s, flag, ERROR_LIGHT);
	ft_advance_isspace(&s);
	ob->ratio = set_double(&s, flag);
	ft_advance_isspace(&s);
	ob->color = set_color(&s, flag);
	ft_advance_isspace(&s);
	if (*flag >= 0 && (ob->color == -1 || \
		!ft_isin_double(0, ob->ratio, 1) || *s != 0))
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
	object_shift(img);
	object_rotaion(img);
}
