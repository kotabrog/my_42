/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:38:22 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/19 21:43:32 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_type(t_data *img, char *s, int *flag, t_type *type_flag)
{
	if (type_flag->first == 0 && type_flag->second == 0)
		set_resolution(img, ++s, flag, type_flag);
	else if (type_flag->first == 1 && type_flag->second == 0)
		set_ambient_light(img, ++s, flag, type_flag);
	else if (type_flag->first == 2 && type_flag->second == 0)
		set_camera(img, ++s, flag);
	else if (type_flag->first == 3 && type_flag->second == 0)
		set_light(img, ++s, flag);
	else if (type_flag->first == 4 && type_flag->second == 1)
		set_sphere(img, ++s, flag);
	else if (type_flag->first == 5 && type_flag->second == 2)
		set_plane(img, ++s, flag);
	else if (type_flag->first == 4 && type_flag->second == 3)
		set_square(img, ++s, flag);
	else if (type_flag->first == 2 && type_flag->second == 4)
		set_cylinder(img, ++s, flag);
	else if (type_flag->first == 6 && type_flag->second == 5)
		set_triangle(img, ++s, flag);
	else
		*flag = ERROR_TYPE;
}

void	check_line_info(t_data *img, char *s, int *flag, t_type *type_flag)
{
	if (*s == 0)
		return ;
	ft_advance_isspace(&s);
	if ((type_flag->first = ft_strchr_n("RAclspt", *s)) >= 0)
		if ((type_flag->second = \
			(ft_isspace(*(++s)) ? 0 : ft_strchr_n(" plqyr", *s))) >= 1)
			if (!ft_isspace(*(++s)))
				type_flag->first = -1;
	check_type(img, s, flag, type_flag);
}

void	get_object_data(t_vars *vars, char *argv)
{
	int			fd;
	int			flag;
	char		*buff;
	t_type		type_flag;

	type_flag.resolution = FALSE;
	type_flag.ambient = FALSE;
	fd = open(argv, 0);
	if (fd < 0)
		exit_error(vars, ERROR_OPEN, POINT_NOT_FREE);
	while((flag = get_next_line(fd, &buff)) >= 0)
	{
		check_line_info(&(vars->img), buff, &flag, &type_flag);
		free(buff);
		buff = NULL;
		if (flag <= 0)
			break ;
	}
	close(fd);
	if (flag)
		exit_error(vars, flag, POINT_DATA_FREE);
	if (!type_flag.resolution || !type_flag.ambient)
		exit_error(vars, ERROR_MISSING, POINT_DATA_FREE);
}

void	check_arg(t_vars *vars, int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") != 0)
			exit_error(vars, ERROR_SAVEFLAG, POINT_NOT_FREE);
		(vars->img).save_flag = TRUE;
	}
	if (argc != 2 && argc != 3)
		exit_error(vars, ERROR_ARGC, POINT_NOT_FREE);
	if (!is_rt_file(argv[1]))
		exit_error(vars, ERROR_RT_FILE, POINT_NOT_FREE);
	get_object_data(vars, argv[1]);
}
