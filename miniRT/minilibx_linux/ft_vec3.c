/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:48:01 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/08 23:58:03 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		vec_equal(t_vec *a, t_vec *b)
{
	return (a->x == b->x && a->y == b->y && a->z == b->z);
}

int		vec_check_nonzero(t_vec *v)
{
	t_vec zero_vec;

	vec_set_inplace(&zero_vec, 0, 0, 0);
	return (!vec_equal(v, &zero_vec));
}

void	vec_atob(t_vec *dst, t_vec *a, t_vec *b)
{
	*dst = vec_product_scaler(a, -1);
	vec_add_inplace(dst, b);
}
