/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:14:37 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/11 20:03:01 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isin_double(double a, double b, double c)
{
	return (a <= b && b <= c);
}

int	ft_isin_int(int a, int b, int c)
{
	return (a <= b && b <= c);
}

int	ft_isin_int_nequal(int a, int b, int c)
{
	return (a < b && b < c);
}

int	ft_isin_double_vec(double a, t_vec *b, double c)
{
	return (a <= b->x && b->x <= c && \
			a <= b->y && b->y <= c && \
			a <= b->z && b->z <= c);
}

// int	ft_isin_double_vec_nequal(double a, t_vec *b, double c)
// {
// 	return (a < b->x && b->x < c && \
// 			a < b->y && b->y < c && \
// 			a < b->z && b->z < c);
// }