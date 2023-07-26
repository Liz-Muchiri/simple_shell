#include "shell.h"
/**
 * lineinterpreter - interprets command line
 * Return: always 0
 */
int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
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
			if (execlp(command, command, NULL) == -1)
			{
				perror("execlp");
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
