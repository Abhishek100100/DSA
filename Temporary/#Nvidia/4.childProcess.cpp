#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // For fork(), getpid(), getppid()
#include <sys/wait.h> // For wait()

int main() {
    printf("Main program started with PID: %d\n\n", getpid());

    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        // --- This block is executed by the CHILD process ---
        printf("--- Child Process --- \n");
        printf("I am the child process.\n");
        printf("My PID is: %d\n", getpid());
        printf("My parent's PID is: %d\n", getppid());
        printf("Child process is exiting.\n");
        exit(0); // Child exits
    } else {
        // --- This block is executed by the PARENT process ---
        printf("--- Parent Process --- \n");
        printf("I am the parent process.\n");
        printf("My PID is: %d\n", getpid());
        printf("I just created a child process with PID: %d\n", pid);

        // Parent waits for the child process to terminate
        int status;
        wait(&status); // Block until child exits

        printf("\nParent knows that the child has finished.\n");
        printf("Parent process is exiting.\n");
    }

    return 0;
}
