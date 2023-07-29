#include "shell.h"
/**
 * shell_exit - implements the builtin exit function
 * Return: 0 always
 */
int shell_exit(void)
{
	char *path, *pathToken, *token, *command = NULL;
	size_t command_size = 0;
	char  commandPath[MAX_COMMAND_LENGTH], *arguments[MAX_ARGUMENTS];
	char prompt[] = "simple_shell> ";
	int status, argCount;
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
		token = strtok(command, " ");

		argCount = 0;

		while (token != NULL && argCount < MAX_ARGUMENTS - 1)
		{
			arguments[argCount++] = token;
			token = strtok(NULL, " ");
		}

		arguments[argCount] = NULL;
		if (strcmp(arguments[0], "exit") == 0)
			break;
		path = getenv("PATH");
		pathToken = strtok(path, ":");

		while (pathToken != NULL)
		{

			snprintf(commandPath, sizeof(commandPath),
					"%s/%s", pathToken, arguments[0]);

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
					waitpid(pid, &status, 0);
				break;
			}

			pathToken = strtok(NULL, ":");
		}
	}
	return (0);
}
