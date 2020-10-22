/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:14:23 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/06/28 13:09:12 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *p;

	if ((p = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}
