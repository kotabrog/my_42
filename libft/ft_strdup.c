/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 23:55:40 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/14 10:54:15 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	n;

	n = ft_strlen(s);
	if ((p = (char *)malloc(n + 1)) == NULL)
		return (NULL);
	ft_strncpy(p, s, n);
	p[n] = 0;
	return (p);
}
