#include "get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("File(s) name(s) missing.");
        return (1);
    }

    int fds[argc - 1];
    char *line;
    int files_opened = 0;

    for (int i = 1; i < argc; i++)
    {
        fds[i - 1] = open(argv[i], O_RDONLY);
        if (fds[i - 1] < 0)
        {
            printf("Error opening file %s.", argv[i]);
            for (int j = 0; j < i - 1; j++)
                close(fds[j]);
            return (1);
        }
        files_opened++;
    }

    int lines_read = 1;
    int lines_available = 1;

    while (lines_available)
    {
        lines_available = 0;
        for (int i = 0; i < files_opened; i++)
        {
            line = get_next_line(fds[i]);
            if (line)
            {
                printf("Line %d from file %s: %s", lines_read, argv[i + 1], line);
                free(line);
                lines_available = 1;
            }
        }
        lines_read++;
    }

    for (int i = 0; i < files_opened; i++)
        close(fds[i]);

    return (0);
}
