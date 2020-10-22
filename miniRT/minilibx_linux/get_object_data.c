/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:38:22 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/10/18 16:08:46 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_type(t_data *img, char *s, int *flag, int type[2])
{
	if (type[0] == 0 && type[1] == 0)
		set_resolution(img, ++s, flag);
	else if (type[0] == 1 && type[1] == 0)
		set_ambient_light(img, ++s, flag);
	else if (type[0] == 2 && type[1] == 0)
		set_camera(img, ++s, flag);
	else if (type[0] == 3 && type[1] == 0)
		set_light(img, ++s, flag);
	else if (type[0] == 4 && type[1] == 1)
		set_sphere(img, ++s, flag);
	else if (type[0] == 5 && type[1] == 2)
		set_plane(img, ++s, flag);
	else if (type[0] == 4 && type[1] == 3)
		set_square(img, ++s, flag);
	else if (type[0] == 2 && type[1] == 4)
		set_cylinder(img, ++s, flag);
	else if (type[0] == 6 && type[1] == 5)
		set_triangle(img, ++s, flag);
	else
		*flag = ERROR_TYPE;
}

void	check_line_info(t_data *img, char *s, int *flag)
{
	int type[2];

	if (*s == 0)
		return ;
	while (ft_isspace(*s))
		s++;
	if ((type[0] = ft_strchr_n("RAclspt", *s)) >= 0)
		if ((type[1] = \
			(ft_isspace(*(++s)) ? 0 : ft_strchr_n(" plqyr", *s))) >= 1)
			if (!ft_isspace(*(++s)))
				type[0] = -1;
	check_type(img, s, flag, type);
}

int		get_object_data(t_data *img, char *argv)
{
	int		fd;
	int		flag;
	char	*s;

	fd = open(argv, 0);
	if (fd < 0)
		return (ERROR_OPEN);
	while((flag = get_next_line(fd, &s)) >= 0)
	{
		check_line_info(img, s, &flag);
		free(s);
		s = NULL;
		if (flag <= 0)
			break ;
	}
	close(fd);
	if (flag == 0 && (!(img->flag[0]) || !(img->flag[1])))
		flag = ERROR_MISSING;
	return (flag);
}
