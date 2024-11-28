#include "get_next_line.h"

size_t readwholefile(int fd, char **f) {
    int check_endofile;
    char *buf;
    char *temp;

    *f = ft_calloc(1, sizeof(char));
    if (!*f) return -1;

    while (1) {
        buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
        if (!buf) return -1;

        check_endofile = read(fd, buf, BUFFER_SIZE);
        if (check_endofile == -1) {
            free(buf);
            return check_endofile;
        }
        if (check_endofile == 0) {
            free(buf);
            break;
        }

        temp = ft_strjoin(*f, buf);
        free(*f);
        *f = temp;
        free(buf);
    }
    return check_endofile;
}

char *get_line(s_buffer *d) {
    int i = 0;
    char *s;
    char *buffer = d->buffer + d->offset;

    while (buffer[i] && buffer[i] != '\n') i++;

    s = malloc(sizeof(char) * (i + 2));
    if (!s) return NULL;

    for (int j = 0; j < i; j++) s[j] = buffer[j];
    if (buffer[i] == '\n') s[i++] = '\n';
    s[i] = '\0';

    d->offset += i;
    return s;
}

char *get_next_line(int fd) {
    static s_buffer static_buffer;
    char *line;

    if (!static_buffer.buffer) {
        static_buffer.buffer = ft_calloc(1, sizeof(char));
        if (!static_buffer.buffer) return NULL;

        size_t read_bytes = readwholefile(fd, &static_buffer.buffer);
        if (read_bytes == -1) {
            free(static_buffer.buffer);
            static_buffer.buffer = NULL;
            return NULL;
        }
    }

    line = get_line(&static_buffer);

    if (!line && static_buffer.offset == 0) {
        free(static_buffer.buffer);
        static_buffer.buffer = NULL;
    }

    return line;
}

int main(void) {
    int fd = open("t.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

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
