#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t ft_read(int fd, const void *buf, size_t count);
int ft_strcmp(char *s1, char *s2);
char *ft_strcpy(char *dst, char *src);
char *ft_strdup(const char *s);
size_t ft_strlen(char *s);
ssize_t ft_write(int fd, const void *buf, size_t count);

int main()
{
	int fd;
	char buf[100];
	ssize_t d;
	size_t n;
	char *s1;
	char *s2;
	char *src;
	char dst[1000];
	char *p;
	int di[20];
	char *str;

	fd = open("main.c", 0);
	n = 10;
	d = ft_read(fd, buf, n);
	buf[n] = '\0';
	printf("%ld, %s\n", d, buf);
	close(fd);
	if (errno)
		perror(NULL);

	fd = open("main.c", 0);
	n = 100;
	d = ft_read(fd, buf, n);
	buf[n] = '\0';
	printf("%ld, %s\n", d, buf);
	close(fd);
	if (errno)
		perror(NULL);

	fd = open("main.c", 0);
	n = 0;
	d = ft_read(fd, buf, n);
	buf[n] = '\0';
	printf("%ld, %s\n", d, buf);
	close(fd);
	if (errno)
		perror(NULL);

	n = 100;
	d = ft_read(fd, buf, n);
	printf("%ld, %s\n", d, buf);
	if (errno)
		perror(NULL);

	printf("------------------------------------\n");

	s1 = "abcde";
	s2 = "abcde";
	printf("%d, %s, %s\n", ft_strcmp(s1, s2), s1, s2);

	s1 = "abcd";
	s2 = "abcde";
	printf("%d, %s, %s\n", ft_strcmp(s1, s2), s1, s2);

	s1 = "abcde";
	s2 = "abcd";
	printf("%d, %s, %s\n", ft_strcmp(s1, s2), s1, s2);

	s1 = "aacde";
	s2 = "abcde";
	printf("%d, %s, %s\n", ft_strcmp(s1, s2), s1, s2);

	s1 = "abcde";
	s2 = "aacde";
	printf("%d, %s, %s\n", ft_strcmp(s1, s2), s1, s2);

	s1 = "";
	s2 = "abcde";
	printf("%d, %s, %s\n", ft_strcmp(s1, s2), s1, s2);

	s1 = "";
	s2 = "";
	printf("%d, %s, %s\n", ft_strcmp(s1, s2), s1, s2);

	s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	printf("%d, %s, %s\n", ft_strcmp(s1, s2), s1, s2);

	printf("------------------------------------\n");

	src = "abcde";
	p = ft_strcpy(dst, src);
	printf("%d, %s, %s\n", p == dst, src, dst);

	src = "abc";
	p = ft_strcpy(dst, src);
	printf("%d, %s, %s\n", p == dst, src, dst);

	src = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	p = ft_strcpy(dst, src);
	printf("%d, %s, %s\n", p == dst, src, dst);

	src = "";
	p = ft_strcpy(dst, src);
	printf("%d, %s, %s\n", p == dst, src, dst);

	printf("------------------------------------\n");

	src = "abcde";
	p = ft_strdup(src);
	printf("%s, %s\n", src, p);
	if (errno)
		perror(NULL);
	free(p);

	src = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	p = ft_strdup(src);
	printf("%s, %s\n", src, p);
	if (errno)
		perror(NULL);
	free(p);

	src = "";
	p = ft_strdup(src);
	printf("%s, %s\n", src, p);
	if (errno)
		perror(NULL);
	free(p);

	printf("------------------------------------\n");

	str = "abcde";
	di[0] = ft_write(1, str, 5);
	write(1, "\n", 1);

	str = "abcde";
	di[1] = ft_write(1, str, 6);
	write(1, "\n", 1);

	str = "abcde";
	di[2] = ft_write(1, str, 4);
	write(1, "\n", 1);

	str = "abcde";
	di[3] = ft_write(1, str, 0);
	write(1, "\n", 1);

	str = "";
	di[4] = ft_write(1, str, 0);
	write(1, "\n", 1);

	str = "";
	di[5] = ft_write(1, str, 1);
	write(1, "\n", 1);

	str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	di[6] = ft_write(1, str, 200);
	write(1, "\n", 1);

	str = "abcde";
	di[7] = ft_write(2, str, 5);
	write(2, "\n", 1);

	if (errno)
		perror(NULL);

	str = "abcde";
	di[8] = ft_write(3, str, 5);
	write(1, "\n", 1);

	if (errno)
		perror(NULL);

	str = NULL;
	di[9] = ft_write(1, str, 5);
	write(1, "\n", 1);

	if (errno)
		perror(NULL);

	str = "abcde";
	di[10] = ft_write(1, str, -1);
	write(1, "\n", 1);

	if (errno)
		perror(NULL);

	for (int i = 0; i < 11; ++i)
		printf("%d, ", di[i]);
	printf("\n");

	printf("------------------------------------\n");

	str = "abcde";
	printf("%s: %ld\n", str, ft_strlen(str));

	str = "abc";
	printf("%s: %ld\n", str, ft_strlen(str));

	str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	printf("%s: %ld\n", str, ft_strlen(str));

	str = "";
	printf("%s: %ld\n", str, ft_strlen(str));

	printf("------------------------------------\n");

/*
	fd = open("main.c", 0);
	n = 10;
	d = read(fd, buf, n);
	buf[n] = '\0';
	printf("%ld, %s\n", d, buf);
	close(fd);
	if (errno)
		perror(NULL);

	fd = open("main.c", 0);
	n = 100;
	d = read(fd, buf, n);
	buf[n] = '\0';
	printf("%ld, %s\n", d, buf);
	close(fd);
	if (errno)
		perror(NULL);

	fd = open("main.c", 0);
	n = 0;
	d = read(fd, buf, n);
	buf[n] = '\0';
	printf("%ld, %s\n", d, buf);
	close(fd);
	if (errno)
		perror(NULL);

	n = 100;
	d = read(fd, buf, n);
	buf[n] = '\0';
	printf("%ld, %s\n", d, buf);
	if (errno)
		perror(NULL);

	printf("------------------------------------\n");

	s1 = "abcde";
	s2 = "abcde";
	printf("%d, %s, %s\n", strcmp(s1, s2), s1, s2);

	s1 = "abcd";
	s2 = "abcde";
	printf("%d, %s, %s\n", strcmp(s1, s2), s1, s2);

	s1 = "abcde";
	s2 = "abcd";
	printf("%d, %s, %s\n", strcmp(s1, s2), s1, s2);

	s1 = "aacde";
	s2 = "abcde";
	printf("%d, %s, %s\n", strcmp(s1, s2), s1, s2);

	s1 = "abcde";
	s2 = "aacde";
	printf("%d, %s, %s\n", strcmp(s1, s2), s1, s2);

	s1 = "";
	s2 = "abcde";
	printf("%d, %s, %s\n", strcmp(s1, s2), s1, s2);

	s1 = "";
	s2 = "";
	printf("%d, %s, %s\n", strcmp(s1, s2), s1, s2);

	s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	printf("%d, %s, %s\n", strcmp(s1, s2), s1, s2);

	printf("------------------------------------\n");

	src = "abcde";
	p = strcpy(dst, src);
	printf("%d, %s, %s\n", p == dst, src, dst);

	src = "abc";
	p = strcpy(dst, src);
	printf("%d, %s, %s\n", p == dst, src, dst);

	src = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	p = strcpy(dst, src);
	printf("%d, %s, %s\n", p == dst, src, dst);

	src = "";
	p = strcpy(dst, src);
	printf("%d, %s, %s\n", p == dst, src, dst);

	printf("------------------------------------\n");

	src = "abcde";
	p = strdup(src);
	printf("%s, %s\n", src, p);
	if (errno)
		perror(NULL);
	free(p);

	src = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	p = strdup(src);
	printf("%s, %s\n", src, p);
	if (errno)
		perror(NULL);
	free(p);

	src = "";
	p = strdup(src);
	printf("%s, %s\n", src, p);
	if (errno)
		perror(NULL);
	free(p);

	printf("------------------------------------\n");

	str = "abcde";
	di[0] = write(1, str, 5);
	write(1, "\n", 1);

	str = "abcde";
	di[1] = write(1, str, 6);
	write(1, "\n", 1);

	str = "abcde";
	di[2] = write(1, str, 4);
	write(1, "\n", 1);

	str = "abcde";
	di[3] = write(1, str, 0);
	write(1, "\n", 1);

	str = "";
	di[4] = write(1, str, 0);
	write(1, "\n", 1);

	str = "";
	di[5] = write(1, str, 1);
	write(1, "\n", 1);

	str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	di[6] = write(1, str, 200);
	write(1, "\n", 1);

	str = "abcde";
	di[7] = write(2, str, 5);
	write(2, "\n", 1);

	if (errno)
		perror(NULL);

	str = "abcde";
	di[8] = write(3, str, 5);
	write(1, "\n", 1);

	if (errno)
		perror(NULL);

	str = NULL;
	di[9] = write(1, str, 5);
	write(1, "\n", 1);

	if (errno)
		perror(NULL);

	str = "abcde";
	di[10] = write(1, str, -1);
	write(1, "\n", 1);

	if (errno)
		perror(NULL);

	for (int i = 0; i < 11; ++i)
		printf("%d, ", di[i]);
	printf("\n");

	printf("------------------------------------\n");

	str = "abcde";
	printf("%s: %ld\n", str, strlen(str));

	str = "abc";
	printf("%s: %ld\n", str, strlen(str));

	str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	printf("%s: %ld\n", str, strlen(str));

	str = "";
	printf("%s: %ld\n", str, strlen(str));

	printf("------------------------------------\n");
*/
}
