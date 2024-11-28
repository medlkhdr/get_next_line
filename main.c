#include "get_next_line.h"
int main(void) {
    int fd = open("t.txt", O_RDONLY);
    char *line;
    for(int i = 0 ; i < 33 ; i++)
    {
        line = get_next_line(fd);
        printf("%s" , line);
        free(line);
    }
    close(fd);
    return 0;
}