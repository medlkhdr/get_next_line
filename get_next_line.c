#include "get_next_line.h"

int readwholefile(int fd, char **f)
{
    int check_endofile;
    char *buf;
    char *temp;

    *f = ft_calloc(1, sizeof(char));
    if (!*f) return -1;

    while (1)
    {
        buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
        if (!buf) {
            free(*f);
            return -1;
        }

        check_endofile = read(fd, buf, BUFFER_SIZE);
        if (check_endofile == -1) {
            free(buf);
            free(*f);
            return -1;
        }
        if (check_endofile == 0)
        {
            free(buf);
            break;
        }

        buf[check_endofile] = '\0';
        temp = ft_strjoin(*f, buf);
        free(*f);
        *f = temp;
        free(buf);

        if (!*f) return -1;
    }

    return 0;
}

char *get_line(s_buffer *d)
{
    int i = 0;
    int j = -1 ;
    char *s;
    char *buffer = d->buffer + d->offset;

    while (buffer[i] && buffer[i] != '\n') i++;

    s = malloc(sizeof(char) * (i + 2));
    if (!s) return NULL;

    while(++j < i)
        s[j] = buffer[j];

    if (buffer[i] == '\n') s[i++] = '\n';
    s[i] = '\0';

    d->offset += i;
    return s;
}

char *get_next_line(int fd)
{
    static s_buffer static_buffer = {NULL, 0};
    char *line;

    if (!static_buffer.buffer)
    {
        int status = readwholefile(fd, &static_buffer.buffer);
        if (status == -1 || !static_buffer.buffer || static_buffer.buffer[0] == '\0')
        {
            if (static_buffer.buffer) free(static_buffer.buffer);
            static_buffer.buffer = NULL;
            return NULL;
        }
    }

    line = get_line(&static_buffer);

    if (!line || static_buffer.buffer[static_buffer.offset] == '\0')
    {
        free(static_buffer.buffer);
        static_buffer.buffer = NULL;
    }

    return line;
}
