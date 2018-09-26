#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 
#include<stdlib.h>

void handler() {
    printf("Stopped.\n");
    exit(0);
}

int main()
{
	int rw[2];

    if (pipe(rw) < 0) {
        return -1;
    }

    int pid1 = fork();
    int pid2 = -256;

    if (pid1 == -1) {
        return -1;
    }

    if (pid1 > 0) {
        pid2 = fork();
    }

    if (pid2 == -1) {
        return -1;
    }

    printf("PID [%d] | Children nodes are P1: [%d] P2: [%d] \n", getpid(), pid1, pid2);

    if (pid1 == 0) {
        printf("Process [%d] | Reads message from parent \n", getpid());
        close(rw[1]);
        read(rw[0], &pid2, sizeof(int));
        close(rw[0]);
        printf("Process [%d] | Gonna terminate [%d] \n", getpid(), pid2);
        if (pid2 != getpid()) {
            sleep(5);
            kill(pid2, SIGSTOP);
            printf("Process [%d] | Terminated [%d] \n", getpid(), pid2);
        }

    } else if (pid1 > 0 & pid2 > 0) {
        printf("Process [%d] | Sends the message to child [%d] \n", getpid(), pid1);
        close(rw[0]);
        write(rw[1], &pid2, sizeof(int));
        close(rw[1]);
        int p = pid2;
        wait(&pid2);
        printf("Process [%d] | Process [%d] is terminated \n ", getpid(), p);

    } else if (pid2 == 0) {
        printf("Process [%d] | Hello world!  \n", getpid());
        while (1) {
            printf("Process [%d] | Still alive! \n", getpid());
            sleep(1);
        }
    }

return 0;
}