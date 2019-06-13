#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/fcntl.h>

// signal catcher method
void sigCatcher()
{
    printf("PID %d caught one\n", getpid());
    kill(getpid() + 1, SIGINT);
}

int main()
{
    pid_t pid;
    signal(SIGINT, sigCatcher);

  // creating the 5 children processes
    for (int i = 0; i < 5; i++)
    {
        if (pid = fork() == 0)
        {
            printf("PID %d ready\n", getpid());
            break;
        }
    }
// at a child process
    if (pid == 0)
    {
        sleep(1);
        kill(getpid() + 1, SIGINT);
    }
    // unsuccesful in creating a child
    else if(pid < 0)
    {
      exit(1);
    }
    // at a parent process
    else
    {
        pause();
        if (getpid() != getppid() + 5)
        {
            kill(getpid() + 1, SIGINT);
        }
        exit(0);
    }

    sleep(1);
    // kill all the zombies
    for (int i = 0; i < 5; i++)
    {
        int zombie = wait(NULL);
        printf("PID %d is dead\n",zombie);
    }

    return 0;
}
