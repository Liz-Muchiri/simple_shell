#include "shell.h"
#define MAX_ARGUMENTS 1000
#define MAX_COMMAND_LENGTH 1024
/**
 * hpath - handles path
 * Return: 0 always
 */
int hpath(void)
{
	char *pathToken, *command = NULL;
	size_t command_size = 0;
	char *token, *path, *delim = " ";
	char prompt[] = "simple_shell> ";
	int status, argCount = 0;
	char *arguments[MAX_ARGUMENTS];
	char commandPath[MAX_COMMAND_LENGTH];
	pid_t pid;

	while (1)
	{
		printf("%s", prompt);

		if (getline(&command, &command_size, stdin) == -1)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';
		token = strtok(command, delim);

		while (token != NULL && argCount < MAX_ARGUMENTS - 1)
		{
			arguments[argCount++] = token;
			token = strtok(NULL, delim);
		}

		arguments[argCount] = NULL;
		path = getenv("PATH");
		pathToken = strtok(path, ":");

		while (pathToken != NULL)
		{
			snprintf(commandPath, sizeof(commandPath), "%s/%s",
					pathToken, arguments[0]);

			if (access(commandPath, X_OK) == 0)
			{
				pid = fork();

				if (pid < 0)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					execve(commandPath, arguments, NULL);
					perror("shell");
					exit(EXIT_FAILURE);
				}
				else
				{

					waitpid(pid, &status, 0);
				}

				break;
			}

			pathToken = strtok(NULL, ":");
		}
	}
	free(command);
	return (0);
}
