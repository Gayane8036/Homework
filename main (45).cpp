#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        sleep(2);
        printf("sending signal\n");
        if (kill(getppid(), SIGKILL) == 0)
        {
            printf("killed\n");
        } else
        {
            printf("error\n");
        }
    }
    else
    {
        sleep(5);
        printf("sleep\n");
    }
    return 0;
}
