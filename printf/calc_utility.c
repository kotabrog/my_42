/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:40:45 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/15 20:13:39 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_get_ndigits(long long n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int				ft_get_ndigits_u(unsigned long long n, int mode)
{
	int i;
	int q;

	i = 0;
	if (!mode)
		q = 10;
	else
		q = 16;
	while (n != 0)
	{
		i++;
		n /= q;
	}
	return (i);
}

unsigned int	ft_abs(int n)
{
	return ((n < 0 ? -1 : 1) * n);
}

int				ft_divrem(int n, int q, int mode)
{
	if (q == 0)
		return (n);
	if (n == INT_MIN && q == -1)
		return (INT_MIN);
	if (mode == 0)
		return (n - (n / q) * q);
	if (mode == 1)
	{
		if (n >= 0)
		{
			if (q > 0)
				return (n - (n / q) * q);
			else
				return (n - (n / (q - 1) - 1) * q);
		}
		else
		{
			if (q > 0)
				return (n - (n / (q + 1) - 1) * q);
			else
				return (n - (n / q) * q);
		}
	}
	return (ft_abs(n - (n / q) * q));
}
