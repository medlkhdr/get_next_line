#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#define BUFFERSIZE 10
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strncpy(char *dest, char *src, unsigned int n );
char	*ft_strcat(char *dest, char *src);
void *ft_realloc(void *ptr, size_t old_size, size_t new_size);
size_t	ft_strlen(const char *s);
#endif