/* p_print_argv_env.c */

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[])
{
    int j;
    char **ep;

    /* Display argument list */

    for (j = 0; j < argc; j++)
        printf("argv[%d] = %s\n", j, argv[j]);

    /* Display environment list */

    for (ep = environ; *ep != NULL; ep++)
        printf("environ: %s\n", *ep);

    exit(EXIT_SUCCESS);
}
