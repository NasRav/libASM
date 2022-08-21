#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

size_t	ft_strlen(char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_write(int fd, const void *buf, size_t count);
size_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

int	main(void)
{
	char	*s;
	char	*copy;
	int		fd;

	s = (char *)malloc(sizeof(char) * 100 + 1);
	s = strdup("Hello, World!");
	printf("ft_strlen.s	=	%ld\n", ft_strlen(s));
	printf("strlen		=	%ld\n", strlen(s));

	copy = (char *)malloc(sizeof(char) * 100 + 1);
	bzero(copy, 100);
	s = strdup("ft_strcpy.s");
	ft_strcpy(copy, s);
	printf("%s\n", copy);
	bzero(copy, 100);
	s = strdup("strcpy");
	strcpy(copy, s);
	printf("%s\n", copy);

	copy = strdup("Hello, World");
	printf("ft_strcmp.s	=	%d\n", ft_strcmp(s, copy));
	printf("strcmp		=	%d\n", strcmp(s, copy));

	s = strdup("ft_write.s");
	ft_write(1, s, 10);
	ft_write(1, "\n", 1);
	copy = strdup("write");
	write(1, copy, 5);
	write(1, "\n", 1);

	bzero(copy, 100);
	fd = open("main.c", O_RDONLY);
	ft_read(fd, copy, 10);
	printf("%s\n", copy);
	bzero(copy, 100);
	fd = open("main.c", O_RDONLY);
	read(fd, copy, 13);
	printf("%s\n", copy);

	bzero(s, 100);
	s = ft_strdup("ft_strdup.s");
	printf("%s\n", s);
	bzero(copy, 100);
	copy = strdup("strdup");
	printf("%s\n", copy);

	return (0);
}
