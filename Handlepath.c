#include "shell.h"
/**
 * _path - handles path
 * Return: 0 always
 */
int _path(void)
{
	char *pathToken, *command = NULL;
	size_t command_size = 0;
	char *token, *path, *delim = " ";
	char prompt[] = "simple_shell> ";
	int status, argCount;
	char *arguments[MAX_ARGUMENTS];
	pid_t pid;

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
		token = strtok(command, delim);
		argCount = 0;

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
			char commandPath[MAX_COMMAND_LENGTH];

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
					if (execv(commandPath, arguments) == -1)
					{
						perror("execv");
						exit(EXIT_FAILURE);
					}
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
	return (0);
}
