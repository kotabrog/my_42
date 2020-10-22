/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trgb_to_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:17:16 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/17 19:26:04 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		trgb_to_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		trgb_to_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		trgb_to_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		trgb_to_b(int trgb)
{
	return (trgb & 0xFF);
}
