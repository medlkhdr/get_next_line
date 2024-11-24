#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#ifndef BUFFERSIZE
  #define BUFFERSIZE 42
#endif
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*get_next_line(int fd);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void         *ft_realloc(void *ptr, size_t new_size);
char				*ft_strncpy(char *dst, const char *src, size_t dstsize);
#endif