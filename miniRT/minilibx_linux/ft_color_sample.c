/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_sample.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:48:16 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/21 16:48:26 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_opposite_trgb(int trgb)
{
	int t;
	int r;
	int g;
	int b;

	t = trgb_to_t_int(trgb);
	r = (trgb_to_r_int(trgb) + 128) % 256;
	g = (trgb_to_g_int(trgb) + 128) % 256;
	b = (trgb_to_b(trgb) + 128) % 256;
	return (create_trgb(t, r, g, b));
}

int		add_double_transparency(double t, int trgb)
{
	return ((int)round(t * 255) << 24 | (0xffffff & trgb));
}
