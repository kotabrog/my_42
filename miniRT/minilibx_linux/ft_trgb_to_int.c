/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trgb_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:27:26 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/17 19:27:45 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		trgb_to_t_int(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int		trgb_to_r_int(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int		trgb_to_g_int(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}
