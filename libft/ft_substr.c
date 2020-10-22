/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:31:42 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/14 11:31:36 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	n;

	if (s == NULL)
		return (NULL);
	n = ft_strlen(s);
	if (n < start)
		len = 0;
	else
		len = (n < start + len ? n - start : len);
	if ((p = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	ft_strncpy(p, s + start, len);
	p[len] = 0;
	return (p);
}
