/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:52:22 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/09/20 12:04:13 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>


// int	main(void)
// {
// 	int fd = 0;
// 	char *line;

// 	// get_next_line(fd, &line);
// 	// long long sample = 0;
// 	// int i = 2000000000, j = 2000000000;
// 	// sample = (long long)i + j;
// 	// printf("%lld", sample);

// 	// char *p;
// 	// ssize_t a;
// 	// p = ft_strchr_ex("abcdefg", 'h', &a);
// 	// printf("%s, %ld", p, a);

// 	// ssize_t a = -1;
// 	// printf("%ld\n", a);

// }


int		main(int argc, char **argv)
{
	int i;
	int n;
	int fd[MAX_FD];
	char *p;
	int flag = 1;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			fd[i] = open(argv[i], 0);
			i++;
		}
		while (flag)
		{
			i = 1;
			flag = 0;
			while (i < argc)
			{
				if (fd[i] && (n = get_next_line(fd[i], &p)) == 0)
				{
					close(fd[i]);
					fd[i] = 0;
				}
				if (p != NULL)
				{
					flag = 1;
				}
				else
					n = 0;
				printf("%d: ", n);
				printf("%s, ", p);
				free(p);
				p = NULL;
				i++;
			}
			printf("\n");
		}
		// while ((n = get_next_line(fd[i], &p)) > 0)
		// {
		// 	while (i < argc)
		// 	printf("%s\n", p);
		// }
		// if (n == 0)
		// 	printf("%s\n", p);
		// printf("%d\n", i);
	}
	else
	{
		while ((n = get_next_line(0, &p)) > 0)
		{
			printf("%s\n", p);
		}
	}
	
	return (0);
	// if (i == 1)
	// 	if (i > 0)
	// 		printf("ok\n");
	// printf("%d\n", (i < 0 ? -1 : i == 0 ? 0 : 1));
}

// int		ft_strlen(char *str)
// {
// 	char *s;

// 	s = str;
// 	while (*str)
// 		str++;
// 	return (str - s);
// }

// void	ft_putstr(int chan, char *str)
// {
// 	write(chan, str, ft_strlen(str));
// }

// void	ft_display_file(char *file, char *program_name)
// {
// 	int		fd;
// 	int		n;
// 	char	buffer[2];

// 	fd = open(file, 0);
// 	if (fd == -1)
// 	{
// 		ft_putstr(2, program_name);
// 		ft_putstr(2, ": ");
// 		ft_putstr(2, file);
// 		ft_putstr(2, ": No such file or directory\n");
// 		return ;
// 	}
// 	while ((n = read(fd, buffer, 2)) > 0)
// 		write(1, buffer, n);
// 	close(fd);
// }

// void	ft_display_stdin(void)
// {
// 	int		n;
// 	char	buffer[2];
// 	char	p[1];

// 	while ((n = read(0, buffer, 2)) > 0)
// 	{
// 		p[0] = n + '0';
// 		write(1, buffer, n);
// 		write(1, ", ", 2);
// 		write(1, p, 1);
// 		write(1, ", ", 2);
// 		if (buffer[2] == 0)
// 			write(1, "null", 4);
// 		write(1, "\n", 1);
// 	}
// }

// int		main(int argc, char **argv)
// {
// 	int i;

// 	i = 1;
// 	if (argc > 1)
// 	{
// 		while (i < argc)
// 		{
// 			ft_display_file(argv[i++], basename(argv[0]));
// 		}
// 	}
// 	else
// 		ft_display_stdin();
// 	return (0);
// }