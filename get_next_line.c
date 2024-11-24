#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stock = NULL;
    char buffer[BUFFERSIZE + 1];
    char *line = NULL;
    int bytes_read, i, j, line_length;

    if (fd < 0 || BUFFERSIZE <= 0)
        return NULL;

    if (!stock)
        stock = ft_calloc(1, sizeof(char));

    while (1)
    {
        bytes_read = read(fd, buffer, BUFFERSIZE);
        if (bytes_read <= 0)
            break;

        buffer[bytes_read] = '\0';
        stock = ft_realloc(stock, ft_strlen(stock ), ft_strlen(stock) + bytes_read + 1);
        ft_strcat(stock, buffer);

        if (ft_strchr(stock, '\n'))
            break;
    }

    if (!stock || !*stock)
        return NULL;
      i = 0 ;
      while(stock[i] != '\n' && stock[i] != '\0')
        i++;
    line = malloc(i + 1);
    ft_strncpy(line, stock, i);
    line[i] = '\0';

    if (stock[i] == '\n')
        i++;

    line_length = ft_strlen(stock) - i;
    char *new_stock = malloc(line_length + 1);
    for (j = 0; j < line_length; j++)
        new_stock[j] = stock[i + j];
    new_stock[line_length] = '\0';

    free(stock);
    stock = new_stock;

    return line;
}
int main(void)
{
   int fd = open("c.txt" , O_RDONLY);
   char *s  = get_next_line(fd);
   printf("%s " , s);
   s = get_next_line(fd);
   printf("\n%s" ,s);

}
