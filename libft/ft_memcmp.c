/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:34:16 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/13 14:59:26 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	const unsigned char	*q;

	i = 0;
	if (s1 == NULL || s2 == NULL || n == 0)
		return (0);
	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	while (i < n - 1 && *(p + i) == *(q + i))
		i++;
	return (*(p + i) - *(q + i));
}
