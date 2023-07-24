#include "shell.h"
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
/**
 * main - handles path
 * Return: 0 always
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char prompt[] = "simple_shell> ";

	while (1)
	{
		printf("%s", prompt);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';
		char *arguments[MAX_ARGUMENTS];
		char delim[] = " \n";
		char *token = strtok(command, delim);
		int argCount = 0;

		while (token != NULL && argCount < MAX_ARGUMENTS - 1)
		{
			arguments[argCount++] = token;
			token = strtok(NULL, delim);
		}

		arguments[argCount] = NULL;
		char *path = getenv("PATH");
		char *pathToken = strtok(path, ":");

		while (pathToken != NULL)
		{
			char commandPath[MAX_COMMAND_LENGTH];

			snprintf(commandPath, sizeof(commandPath), "%s/%s",
					pathToken, arguments[0]);

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
				{
					int status;

					waitpid(pid, &status, 0);
				}

				break;
			}

			pathToken = strtok(NULL, ":");
		}
	}
	return (0);
}
