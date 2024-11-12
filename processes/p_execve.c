/* p_execve.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    char *newargv[] = { NULL, "Russia", "Moscow", NULL };
    char *newenviron[] = { "University=MEPhI", NULL };

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    newargv[0] = strrchr(argv[1], '/'); /* Get basename from argv[1] */
    if (newargv[0] != NULL)
        newargv[0]++;
    else
        newargv[0] = argv[1];

    execve(argv[1], newargv, newenviron);
    perror("execve"); /* execve() returns only on error */
    exit(EXIT_FAILURE);
}
