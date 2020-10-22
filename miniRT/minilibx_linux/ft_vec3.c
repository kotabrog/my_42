/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:48:01 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/30 18:18:35 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		vec_equal(t_vec a, t_vec b)
{
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

int		vec_check_nonzero(t_vec v)
{
	return (!vec_equal(v, vec_set(0, 0, 0)));
}
