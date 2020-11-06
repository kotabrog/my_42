/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:48:45 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/06 22:43:13 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t		ft_strlen(const char *s)
{
	ssize_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*(s + i))
		i++;
	return (i);
}

void		ft_strcpy(char *p, char const *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
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

char		*ft_strndup(const char *s, ssize_t n)
{
	char	*p;

	if (s == NULL)
		n = 0;
	else if (n < 0)
		n = ft_strlen(s);
	if ((p = (char *)malloc(n + 1)) == NULL)
		return (NULL);
	ft_strcpy(p, s, n);
	p[n] = 0;
	return (p);
}

char		*ft_strjoin_ex(char *s1, char *s2, ssize_t n1, ssize_t n2)
{
	char	*p;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (n1 < 0)
		n1 = ft_strlen(s1);
	if (n2 < 0)
		n2 = ft_strlen(s2);
	if ((p = (char *)malloc(n1 + n2 + 1)) == NULL)
		return (NULL);
	ft_strcpy(p, s1, n1);
	ft_strcpy(p + n1, s2, n2);
	p[n1 + n2] = 0;
	return (p);
}
