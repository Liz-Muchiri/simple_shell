#include "shell.h"
/**
 * lineinterpreter - interprets command line
 * Return: always 0
 */
int lineinterpreter(void)
{
	char command[2];
	char prompt[] = "simple_shell> ";
	int status;
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
		pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(command, command, NULL) == -1)
			{
				perror("execve");
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
