#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int main() {
    pid_t pid;
    int counter = 0;
    pid = fork();

    // check if fork fails
    if (pid < 0) {
        perror ("fork() failed");
        exit(1);
    // child process branch
    } else if (pid == 0) {
        while (1) {
            printf("Process 1 - pid: %d, counter: %d\n", getpid(), counter ++);
            sleep(1);
        }
    // parent process branch
    } else {
        while (1) {
            printf("Process 2 - pid: %d, counter: %d\n", getpid(), counter ++);
            sleep(1);
        }
    }
    return 0;
}
