/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:26:47 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/13 15:22:17 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	if (src < dest && n != 0)
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
