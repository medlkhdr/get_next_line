#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 30
#endif
#include<stdint.h>
#include<limits.h>
struct s_static_buffer
{
	char *buffer;
	int offset;
};
typedef struct s_static_buffer s_buffer;
char *get_next_line(int fd);
void ft_bzero(void *s , size_t n);
char *ft_strjoin(char const *s1 , char const *s2 );
char  *ft_strdup(const char *s1);
size_t ft_strlen(const char *s);
void *ft_memset(void *b , int c, size_t len);
void *ft_calloc(size_t count , size_t size);
char *get_line(s_buffer *d);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
