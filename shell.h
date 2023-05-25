#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


char *_getline();
char *space(char *str);
char *enter(char *string);
void hashtag_handler(char *buff);
void prompt(void);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
int history(char *input);
char **separator(char *input);



#endif
