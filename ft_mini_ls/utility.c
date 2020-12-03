/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:54:34 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/03 22:22:43 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_time_cmp(const time_t t1, const time_t t2)
{
	if (t1 > t2)
		return (1);
	else if (t1 == t2)
		return (0);
	return (-1);
}

int			ft_fi_cmp(const t_fi *fi1, const t_fi *fi2)
{
	int temp;

	temp = ft_time_cmp(fi1->time, fi2->time);
	if (temp != 0)
		return (temp);
	temp = ft_time_cmp(fi1->nano_time, fi2->nano_time);
	if (temp != 0)
		return (temp);
	return (-ft_strcmp(fi1->name, fi2->name));
}
