/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:48:45 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/20 12:00:58 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
