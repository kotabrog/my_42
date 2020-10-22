/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:26:58 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/14 10:11:42 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char		*ft_strchr_ex(const char *s, int c, ssize_t *len, int *flag)
{
	const char *start;

	*len = 0;
	if (s == NULL)
		return (NULL);
	start = s;
	while (*s && *s != c)
		s++;
	*len = (ssize_t)(s - start);
	if (*s == c)
		*flag = 1;
	if (*s == c && *(s + 1))
		return ((char *)(s + 1));
	return (NULL);
}
