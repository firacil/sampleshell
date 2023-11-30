#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

void _puts(char *s);
void myexit(void);
void freetok(char **tok, int numtok);
char *get_location(char *command);
void execmd(char **argv);
#endif
