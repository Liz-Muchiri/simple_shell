#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
int lineinterpreter(void);
int token(void);
int shell_exit(void);
int hpath(void;
#endif
