/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:09:03 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/26 01:40:08 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	make_file_name(t_vars *vars, char **file_path, int camera_num)
{
	int		n;
	int		len_name;
	char	*file_name;
	int		i;

	n = ft_get_ndigits(camera_num);
	if ((file_name = ft_strrchr(*file_path, '/')) == NULL)
		file_name = *file_path;
	else
		++file_name;
	len_name = ft_strlen(file_name) - 3;
	if ((*file_path = (char *)malloc(len_name + n + 6)) == NULL)
		exit_error(vars, ERROR_MALLOC, POINT_IMAGE_FREE);
	ft_strcpy(*file_path, file_name, len_name);
	ft_strcpy(*file_path + len_name, "_", 1);
	i = n;
	while (i--)
	{
		(*file_path)[len_name + i + 1] = '0' + camera_num % 10;
		camera_num /= 10;
	}
	ft_strcpy(*file_path + len_name + n + 1, ".bmp", 5);
}

void	add_header(char *file, unsigned int size, t_data *img)
{
	int n;

	ft_memcpy(file, "BM", 2);
	n = size + HEADER_SIZE;
	ft_memcpy(file + 2, &n, 4);
	n = 0;
	ft_memcpy(file + 6, &n, 4);
	n = HEADER_SIZE;
	ft_memcpy(file + 10, &n, 4);
	n = INFO_HEADER_SIZE;
	ft_memcpy(file + 14, &n, 4);
	ft_memcpy(file + 18, &(img->x), 4);
	ft_memcpy(file + 22, &(img->y), 4);
	n = 1;
	ft_memcpy(file + 26, &n, 2);
	n = 24;
	ft_memcpy(file + 28, &n, 2);
	n = 0;
	ft_memcpy(file + 30, &n, 4);
	ft_memcpy(file + 34, &size, 4);
	ft_memcpy(file + 38, &n, 4);
	ft_memcpy(file + 42, &n, 4);
	ft_memcpy(file + 46, &n, 4);
	ft_memcpy(file + 50, &n, 4);
}

void	add_img(char *file, t_data *img)
{
	int x;
	int y;
	int i;
	int j;

	i = HEADER_SIZE;
	y = img->y;
	while (y--)
	{
		x = 0;
		while (x < img->x)
		{
			j = y * img->line_length + x * (img->bits_per_pixel / 8);
			ft_memcpy(file + i, img->addr + j, 3);
			i += 3;
			++x;
		}
	}
}

void	exit_bmp_error(t_vars *vars, t_bmp *bmp, int error_flag)
{
	free(bmp->name);
	free(bmp->file);
	if (bmp->fd > 0)
		close(bmp->fd);
	exit_error(vars, error_flag, POINT_IMAGE_FREE);
}

void	export_bmp(t_vars *vars, t_data *img, char *file_name, int camera_num)
{
	t_bmp			bmp;
	unsigned int	bmp_size;

	bmp.fd = 0;
	make_file_name(vars, &file_name, camera_num);
	bmp.name = file_name;
	img->x = img->x - img->x % 4;
	bmp_size = img->x * img->y * 3;
	if ((bmp.file = (char *)malloc(bmp_size + HEADER_SIZE)) == NULL)
		exit_bmp_error(vars, &bmp, ERROR_MALLOC);
	add_header(bmp.file, bmp_size, img);
	add_img(bmp.file, img);
	if ((bmp.fd = open(bmp.name, (O_RDWR | O_CREAT | O_TRUNC), \
											FILE_PERMISSION)) < 0)
		exit_bmp_error(vars, &bmp, ERROR_CREATE_FILE);
	if (write(bmp.fd, bmp.file, bmp_size + HEADER_SIZE) < 0)
		exit_bmp_error(vars, &bmp, ERROR_WRITE_FILE);
	write(1, bmp.name, ft_strlen(bmp.name));
	write(1, "\n", 1);
	close(bmp.fd);
	free(bmp.name);
	free(bmp.file);
}
