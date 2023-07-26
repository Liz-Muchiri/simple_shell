#include "shell.h"
/**
 * token - tokenising command arguments
 * Return: 0 always
 */
int token(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS], *token;
	char *delim = " ";
	int argCount, status;
	char prompt[] = "simple_shell> ";
	pid_t pid;

	while (1)
	{
		printf("%s", prompt);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
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

		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(arguments[0], arguments) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}
