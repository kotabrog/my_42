/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:59:17 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/06/23 20:58:13 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t n;
	size_t i;

	i = 0;
	n = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			n = i;
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	if (*s != c && n == 0)
		return (NULL);
	return ((char *)(s + n));
}
