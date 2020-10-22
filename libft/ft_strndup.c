/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 22:18:58 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/11 22:20:58 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, ssize_t n)
{
	char	*p;

	if (s == NULL)
		n = 0;
	else if (n < 0)
		n = ft_strlen(s);
	if ((p = (char *)malloc(n + 1)) == NULL)
		return (NULL);
	ft_strncpy(p, s, n);
	p[n] = 0;
	return (p);
}
