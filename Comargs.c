#include "shell.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char prompt[] = "simple_shell> ";

    while (1) {
        printf("%s", prompt);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n");
            break;
        }

        // Remove the newline character at the end of the command
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command into arguments
        char* arguments[MAX_ARGUMENTS];
	char delim[] = " \n";
        char* token = strtok(command, delim);
        int argCount = 0;

        while (token != NULL && argCount < MAX_ARGUMENTS - 1) {
            arguments[argCount++] = token;
            token = strtok(NULL, delim);
        }

        arguments[argCount] = NULL;

        // Fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process

            // Execute the command
            if (execvp(arguments[0], arguments) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process

            // Wait for the child process to finish
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

