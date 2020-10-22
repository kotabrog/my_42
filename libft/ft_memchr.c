/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:12:10 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/13 15:26:27 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	const unsigned char	*cs;
	unsigned char	cc;

	cs = (const unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (cs[i] == cc)
			return ((void *)(cs + i));
		i++;
	}
	return (NULL);
}
