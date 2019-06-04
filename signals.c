#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

// signal catcher method
void sigCatcher()
{
    // signal(SIGINT, sigCatcher);
    printf("PID %d caught one\n", getpid());
    kill(getpid() + 1, SIGINT);
}

int main()
{
    pid_t pid;
    signal(SIGINT, sigCatcher);


    for (int i = 0; i < 5; i++)
    {
        if (pid = fork() == 0)
        {
            printf("PID %d ready\n", getpid());
            break;
        }
    }

    if (pid == 0)
    {
        sleep(1);
        kill(getpid() + 1, SIGINT);
    }

    if (pid > 0)
    {
        pause();
        if (getpid() != getppid() + 5)
        {
            kill(getpid() + 1, SIGINT);
        }
        exit(0);
    }

    sleep(1);
    for (int i = 0; i < 5; i++)
    {
        int zombie = wait(NULL);
            printf("PID %d is dead\n",zombie);
    }
    exit(0);

    return 0;
}
