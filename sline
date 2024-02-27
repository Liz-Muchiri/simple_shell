#include "shell.h"
/**
 * lineinterpreter - interprets command line
 * Return: always 0
 */
int lineinterpreter(void)
{
	char *command = NULL;
	size_t command_size = 0;
	char *args[2];
	char prompt[] = "simple_shell> ";
	int status;
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
		pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			args[0] = command;
			args[1] = NULL;
			execve(command, args, NULL);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	free(command);
	return (0);
}
