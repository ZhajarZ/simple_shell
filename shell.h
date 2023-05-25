#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define BUFSIZE 1024
char *myFunc();
char *myEnter(char *myString);
char *mySpace(char *str);
void myHashtagHandler(char *myBuff);

#endif
