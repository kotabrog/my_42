/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 23:09:28 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/06/28 11:43:49 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((p = malloc(nmemb * size)) == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
