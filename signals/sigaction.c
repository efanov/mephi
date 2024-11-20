#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

sig_atomic_t sig_received = 0;

void handler(int sig)
{
    sig_received = sig;
}

int main(void)
{
    struct sigaction act;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_handler = &handler;

    if (sigaction(SIGINT, &act, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if (sig_received) {
            printf("Received signal %d (%s)\n", sig_received, strsignal(sig_received));
            sig_received = 0;
        }
    }

    exit(EXIT_SUCCESS);
}
