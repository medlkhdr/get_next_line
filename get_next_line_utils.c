#include <stdint.h>
#include<limits.h>
#include<string.h>
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	s = b;
	i = 0;
	while (i < len)
	{
		s[i] = (unsigned char)(c);
		i++;
	}
	return (b);
}
size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
	{
		ptr++;
	}
	return ((size_t)(ptr - s));
}
void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
	{
		return ;
	}
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (count > SIZE_MAX / size)
	{
		return (NULL);
	}
	ptr = malloc(count * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, size * count);
	return (ptr);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)(s));
	return (NULL);
}
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	while (dest && dest[j] != '\0')
		j++;
	dlen = j;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	if (dest)
		dest[j] = '\0';
	return (dlen + slen);
}
void *ft_realloc(void *ptr, size_t old_size, size_t new_size) {
    if (ptr == NULL)
        return malloc(new_size);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    void *new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;
   ft_memcpy(new_ptr, ptr, old_size);
    free(ptr);
    return new_ptr;
}
char	*ft_strncpy(char *dest, char *src, unsigned int n )
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (n--)
	{
		*(d++) = *(s++);
	}
	return (dest);
}