/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:41:54 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/10/18 23:13:25 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	tube_discriminant(t_vec start, t_vec direction, t_object ob)
{
	double d;

	start = vec_add(start, vec_product_scaler(ob.vec, -1));
	ob.vec = vec_set(0, 0, 0);
	start = rotation_inverse_matrix(ob.no_vec, start);
	direction = rotation_inverse_matrix(ob.no_vec, direction);
	start.y = 0;
	direction.y = 0;
	// if (!vec_check_nonzero(direction))
	// 	return (vec_squared_norm(start) == ob.r * ob.r ? ob.r : INFINITY);
	// d = direction.x * start.z - direction.z * start.x;
	// d /= vec_squared_norm(start);
	// return (d * vec_norm(direction));
}

// double	tube_solution(t_vec start, t_vec direction, t_object ob, double d)
// {
// 	start = vec_add(start, vec_product_scaler(ob.vec, -1));
// 	ob.vec = vec_set(0, 0, 0);
// 	start = rotation_inverse_matrix(ob.no_vec, start);
// 	direction = rotation_inverse_matrix(ob.no_vec, direction);
// 	if (direction.x == 0 && direction.z == 0)
// 		return (0);
// 	if (direction.x != 0)
// 		d = -(direction.z * d + start.x) / direction.x;
// 	else
// 		d = (direction.x * d - start.z) / direction.z;
	
// }
