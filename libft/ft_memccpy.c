/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:45:52 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/13 15:35:11 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		uc;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	uc = (unsigned char)c;
	while (n--)
	{
		*d = *s++;
		if (*d++ == uc)
			return ((void *)d);
	}
	return (NULL);
}
