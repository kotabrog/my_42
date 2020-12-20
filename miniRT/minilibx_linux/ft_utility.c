/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 10:37:56 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/19 22:56:09 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int		ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t i;

// 	i = 0;
// 	if ((s1 == NULL && s2 == NULL) || n == 0)
// 		return (0);
// 	while (s1[i] && s1[i] == s2[i] && i < n - 1)
// 		i++;
// 	return (s1[i] - s2[i]);
// }

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

ssize_t	ft_strlen(const char *s)
{
	ssize_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*(s + i))
		i++;
	return (i);
}

int		ft_get_ndigits(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

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
