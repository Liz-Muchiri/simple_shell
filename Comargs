#include "shell.h"
#define MAX_ARGUMENTS 65536
/**
 * token - tokenising command arguments
 * Return: 0 always
 */
int token(void)
{
	char *command = NULL;
	size_t command_size = 0;
	char *arguments[MAX_ARGUMENTS], *token;
	char *delim = " ";
	int argCount, status;
	char prompt[] = "simple_shell> ";
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

		argCount = 0;

		while (token != NULL)
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
		if (pid == 0)
		{
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
	
			waitpid(pid, &status , 0);
		}
	return (0);
}
