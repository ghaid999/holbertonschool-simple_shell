#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void execute_command(char **args);
int read_input(char **line, size_t *line_size);
void parse_arguments(char *line, char **args);
char *find_in_path(char *command);

#endif
