/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 01:00:03 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/03 22:23:13 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fi_malloc(t_fi **fi, int *fi_size)
{
	t_fi	*temp_fi;
	int		i;

	temp_fi = *fi;
	if ((*fi = (t_fi *)malloc((*fi_size + BUFFER) * sizeof(t_fi))) == NULL)
	{
		perror(ERROR_MESSAGE);
		free(temp_fi);
		return (1);
	}
	i = 0;
	while (i < *fi_size)
	{
		(*fi)[i] = temp_fi[i];
		++i;
	}
	free(temp_fi);
	return (0);
}

int		read_and_put(t_fi **fi, int *fi_size, DIR *dir)
{
	struct stat		sb;
	struct dirent	*dp;

	*fi_size = 0;
	*fi = NULL;
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] == '.')
			continue ;
		if (*fi_size % BUFFER == 0)
			if (fi_malloc(fi, fi_size))
				return (1);
		if (lstat(dp->d_name, &sb))
			break ;
		(*fi)[*fi_size].name = dp->d_name;
		(*fi)[*fi_size].time = sb.st_mtime;
		(*fi)[(*fi_size)++].nano_time = sb.st_mtimespec.tv_nsec;
	}
	if (errno)
	{
		perror(ERROR_MESSAGE);
		return (1);
	}
	return (0);
}

void	sort_file_info(t_fi *fi, int fi_size)
{
	t_fi	temp;
	int		i;
	int		j;

	i = 0;
	while (i < fi_size - 1)
	{
		j = i + 1;
		while (j < fi_size)
		{
			if (ft_fi_cmp(&(fi[i]), &(fi[j])) > 0)
			{
				temp = fi[i];
				fi[i] = fi[j];
				fi[j] = temp;
			}
			++j;
		}
		++i;
	}
}

void	print_file_info(t_fi *fi, int fi_size)
{
	int i;

	i = 0;
	while (i < fi_size)
	{
		write(1, fi[i].name, ft_strlen(fi[i].name));
		write(1, "\n", 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	DIR				*dir;
	t_fi			*fi;
	int				fi_size;

	argv[0] = "";
	if (argc > 1)
	{
		write(2, "use one argument\n", 18);
		return (1);
	}
	if ((dir = opendir(".")) == NULL)
	{
		perror(ERROR_MESSAGE);
		return (1);
	}
	if (!read_and_put(&fi, &fi_size, dir))
	{
		sort_file_info(fi, fi_size);
		print_file_info(fi, fi_size);
	}
	free(fi);
	closedir(dir);
}
