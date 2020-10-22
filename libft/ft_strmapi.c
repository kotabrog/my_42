/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:10:39 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/07/14 10:31:28 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;
	unsigned int	n;

	if (s == NULL)
		return (NULL);
	n = ft_strlen(s);
	if ((p = (char *)malloc(n + 1)) == NULL)
		return (NULL);
	i = 0;
	if (f == NULL)
		ft_strncpy(p, s, n);
	else
	{
		while (i < n)
		{
			p[i] = (*f)(i, s[i]);
			i++;
		}
	}
	p[n] = 0;
	return (p);
}
