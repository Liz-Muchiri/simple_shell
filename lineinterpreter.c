#include "shell.h"
/**
 * main - interprets command line
 * Return: always 0
 */
#define MAX_COMMAND_LENGTH 100
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char prompt[] = "simple_shell> ";
	int status;

	while (1)
	{
		printf("%s", prompt);
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		pid_t pid = fork();

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
