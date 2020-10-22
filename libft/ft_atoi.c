/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:24:50 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/10 10:35:33 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	size_t	n;
	int		minus_flag;

	n = 0;
	minus_flag = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		minus_flag = 1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		n = n * 10 + (*nptr++ - '0');
	if (minus_flag)
		n *= -1;
	return ((int)n);
}
