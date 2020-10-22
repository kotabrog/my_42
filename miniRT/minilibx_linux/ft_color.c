/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:28:47 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/21 16:50:30 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		color_product(double ratio, int trgb)
{
	int t;
	int r;
	int g;
	int b;

	t = trgb_to_t_int(trgb);
	r = (int)round(trgb_to_r_int(trgb) * ratio);
	g = (int)round(trgb_to_g_int(trgb) * ratio);
	b = (int)round(trgb_to_b(trgb) * ratio);
	return (create_trgb(t, r, g, b));
}

int		color_max(int trgb1, int trgb2)
{
	int trgb1_array[4];
	int trgb2_array[4];
	int i;

	trgb1_array[0] = trgb_to_t_int(trgb1);
	trgb1_array[1] = trgb_to_r_int(trgb1);
	trgb1_array[2] = trgb_to_g_int(trgb1);
	trgb1_array[3] = trgb_to_b(trgb1);
	trgb2_array[0] = trgb_to_t_int(trgb2);
	trgb2_array[1] = trgb_to_r_int(trgb2);
	trgb2_array[2] = trgb_to_g_int(trgb2);
	trgb2_array[3] = trgb_to_b(trgb2);
	i = 0;
	while (i < 4)
	{
		if (trgb1_array[i] < trgb2_array[i])
			trgb1_array[i] = trgb2_array[i];
		i++;
	}
	return (create_trgb(trgb1_array[0], trgb1_array[1], \
			trgb1_array[2], trgb1_array[3]));
}

int		color_sum(int trgb1, int trgb2)
{
	int trgb1_array[4];
	int trgb2_array[4];
	int i;

	trgb1_array[0] = trgb_to_t_int(trgb1);
	trgb1_array[1] = trgb_to_r_int(trgb1);
	trgb1_array[2] = trgb_to_g_int(trgb1);
	trgb1_array[3] = trgb_to_b(trgb1);
	trgb2_array[0] = trgb_to_t_int(trgb2);
	trgb2_array[1] = trgb_to_r_int(trgb2);
	trgb2_array[2] = trgb_to_g_int(trgb2);
	trgb2_array[3] = trgb_to_b(trgb2);
	i = 0;
	while (i < 4)
	{
		trgb1_array[i] += trgb2_array[i];
		if (trgb1_array[i] > 255)
			trgb1_array[i] = 255;
		i++;
	}
	return (create_trgb(trgb1_array[0], trgb1_array[1], \
			trgb1_array[2], trgb1_array[3]));
}