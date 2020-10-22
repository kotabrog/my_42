/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:02:50 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/14 10:20:16 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	if (size <= dest_size)
		return (size + src_size);
	while (src[i] && dest_size + i < size - 1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = 0;
	return (dest_size + src_size);
}
