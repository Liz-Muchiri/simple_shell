#include "shell.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	char prompt[] = "simple_shell> ";
	int status, argCount;

	while (1)
	{
		printf("%s", prompt);

		if (getline(&command, &command_size, stdin) == -1)
		{
			printf("\n");
			free(command);
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		char *arguments[MAX_ARGUMENTS];
		char *token = strtok(command, " ");

		argCount = 0;

		while (token != NULL && argCount < MAX_ARGUMENTS - 1)
		{
			arguments[argCount++] = token;
			token = strtok(NULL, " ");
		}

		arguments[argCount] = NULL;
		if (strcmp(arguments[0], "exit") == 0)
			break;
		char *path = getenv("PATH");
		char *pathToken = strtok(path, ":");

		while (pathToken != NULL)
		{
			char commandPath[MAX_COMMAND_LENGTH];

			snprintf(commandPath, sizeof(commandPath),
					"%s/%s", pathToken, arguments[0]);

			if (access(commandPath, X_OK) == 0)
			{
				pid_t pid = fork();

				if (pid < 0)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					if (execv(commandPath, arguments) == -1)
					{
						perror("execv");
						exit(EXIT_FAILURE);
					}
				}
				else
					waitpid(pid, &status, 0);
				break;
			}

			pathToken = strtok(NULL, ":");
		}
	}
	return (0);
}
