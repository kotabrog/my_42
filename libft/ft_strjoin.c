/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:01:36 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/11 22:21:17 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	n1;
	size_t	n2;

	n1 = 0;
	n2 = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 != NULL)
		n1 = ft_strlen(s1);
	if (s2 != NULL)
		n2 = ft_strlen(s2);
	if ((p = (char *)malloc(n1 + n2 + 1)) == NULL)
		return (NULL);
	ft_strncpy(p, s1, n1);
	ft_strncpy(p + n1, s2, n2);
	p[n1 + n2] = 0;
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
	ft_strncpy(p, s1, n1);
	ft_strncpy(p + n1, s2, n2);
	p[n1 + n2] = 0;
	return (p);
}
