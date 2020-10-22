/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 10:09:47 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/10 15:48:38 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		num_digits;
	char	*p;

	num_digits = ft_get_ndigits(n);
	if (n <= 0)
		num_digits++;
	if ((p = (char *)malloc((num_digits + 1) * sizeof(char))) == NULL)
		return (NULL);
	p[num_digits--] = 0;
	if (n < 0)
		p[0] = '-';
	if (n == 0)
		p[0] = '0';
	else
	{
		while (n != 0)
		{
			p[num_digits--] = ft_divrem(n, 10, 2) + '0';
			n /= 10;
		}
	}
	return (p);
}
