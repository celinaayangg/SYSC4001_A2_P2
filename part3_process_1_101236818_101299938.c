#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Create a child process
    pid_t pid = fork();

    // Check if fork failed
    if (pid < 0) {
        perror("fork() failed");
        exit(1);
    } 

    // Child process - replaces itself with process2
    else if (pid == 0) {
        execl("./process2", "process2", NULL); 
        perror("exec() failed");
        exit(1);
    } 

    // Parent process continues running here
    else {
        int counter = 0;
        int cycle = 0;

        while (1) {   
            if (counter % 3 == 0)
                printf("P1 - Cycle %d: %d is a multiple of 3\n", cycle, counter);
            else
                printf("P1 - Cycle %d\n", cycle);
            counter++;
            cycle++;
            usleep(100000);   // Sleep for 0.1 seconds (100,000 microseconds)
            int status;
            pid_t result = waitpid(pid, &status, WNOHANG);

            // If child terminated, exit loop
            if (result == pid) {
                printf("P1: Child process ended, parent exiting...\n");
                break;
            }
        }
    }
    return 0;
}
