#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>
// #include <fcntl.h>
// #include <errno.h>

#define MAX_BUFFER_SIZE 16000000 // 16 MB

// PARENT PROCESS
void parent_process(int pipefd[2], int buffer_size)
{
    // Memory Allocation for submitted buffer_size
    char *buffer = malloc(buffer_size);
    if (buffer == NULL)
    {
        perror("Error: allocating memory for buffer failed!");
        exit(1);
    }

    // Fill the allocated memory
    memset(buffer, 'X', buffer_size);

    // Time Measurement Variables
    struct timeval tv_start;
    struct timeval tv_stop;
    double time_delta_sec;
  
    gettimeofday(&tv_start, NULL);         // Get start-time
    int bytes_written = write(pipefd[1], buffer, buffer_size); // Write data into the pipe
    gettimeofday(&tv_stop, NULL);          // Get end-time

    // Write Error Check
    if (bytes_written != buffer_size) {
        perror("Error: Failed to write full buffer to the pipe!");
        exit(EXIT_FAILURE);
      }

    free(buffer);     // Free the allocated memory
    close(pipefd[1]); // Close write end of the pipe in parent process


    time_delta_sec = ((tv_stop.tv_sec - tv_start.tv_sec) + ((tv_stop.tv_usec - tv_start.tv_usec) / (1000.0 * 1000.0)));
    double bandwidth = (buffer_size / (1024.0 * 1024.0)) / time_delta_sec;

    printf("%d Bytes\t%.2f MB/s\n", buffer_size, bandwidth);
}

// CHILD PROCESS
void child_process(int pipefd[2])
{
    char buffer[MAX_BUFFER_SIZE];
    read(pipefd[0], buffer, MAX_BUFFER_SIZE);
    close(pipefd[0]);   // Close read end of the pipe in child process
    exit(EXIT_SUCCESS); // Exit child-process
}

int main(int argc, char *argv[])
{
    // create pipe
    int pipefd[2]; // fd[0]: read, fd[1]: write

    printf("===========================\n");
    printf("Buffer Size  ||   Bandwidth\n");
    printf("===========================\n");

    for (int buffer_size = 64; buffer_size <= MAX_BUFFER_SIZE; buffer_size = buffer_size * 4)
    {
        // Memory Allocation for submitted buffer_size
        char *buffer = malloc(buffer_size);
        if (buffer == NULL)
        {
            perror("Error: allocating memory for buffer failed!");
            exit(EXIT_FAILURE);
        }

        if (pipe(pipefd) == -1)
        {
    perror("Error: pipe creation failed!");
    exit(EXIT_FAILURE);
        }

        // create child-process
        pid_t pid = fork();

        if (pid == -1)
        {
    perror("Error: child process creation failed!");
    exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // Child process
            close(pipefd[1]); // Close write end of the pipe in child process
            child_process(pipefd);
        }
        else
        {
            // Parent process
            close(pipefd[0]); // Close read end of the pipe
            parent_process(pipefd, buffer_size);
        }
        free(buffer);
    }
    return 0;
}