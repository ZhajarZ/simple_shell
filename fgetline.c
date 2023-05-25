#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * myFunc - read input from standard input by user
 * Return: the input on a buffer
 */
char *myFunc()
{
	int index, rd, bufferSize = BUFSIZE;
	char character = 0, *myBuffer, *myBuf;

	myBuffer = malloc(bufferSize);
	if (myBuffer == NULL)
	{
	free(myBuffer);
	return (NULL);
	}
       	for (index = 0; character != EOF && character != '\n'; index++)
	{
        fflush(stdin);
        rd = read(STDIN_FILENO, &character, 1);
        if (rd == 0)
        {
            free(myBuffer);
            exit(EXIT_SUCCESS);
        }
        myBuffer[index] = character;
        if (myBuffer[0] == '\n')
            return (myEnter(myBuffer));
        if (index >= bufferSize)
        {
            myBuffer = realloc(myBuffer, (bufferSize + 2));
            if (myBuffer == NULL)
            {
                free(myBuffer);
                return (NULL);
            }
        }
    }
	myBuffer[index] = '\0';
	myBuf = mySpace(myBuffer);
	free(myBuffer);
	myHashtagHandler(myBuf);
	return (myBuf);
}

/**
 * myEnter - Handles newline character input
 * @myString: String to be handled
 * Return: Empty string
 */
char *myEnter(char *myString)
{
    free(myString);
    return ("\0");
}

/**
 * mySpace - Modifies the input string to remove preceeding whitespaces
 * @str: Input to be modifies
 * Return: Returns the modified string
 */
char *mySpace(char *str)
{
    int i, j = 0;
    char *myBuff;

    myBuff = malloc(sizeof(char) * (strlen(str) + 1));
    if (myBuff == NULL)
    {
        free(myBuff);
        return NULL;
    }
    for (i = 0; str[i] == ' '; i++)
        ;
    for (; str[i + 1] != '\0'; i++)
    {
        myBuff[j] = str[i];
        j++;
    }
    myBuff[j] = '\0';
    if (myBuff[0] == '\0' || myBuff[0] == '#')
    {
        free(myBuff);
        return "\0";
    }
    return myBuff;
}

/**
 * myHashtagHandler - function that removes everything after '#'
 * @myBuff: input buffer
 * Return: nothing
 */
void myHashtagHandler(char *myBuff)
{
	int i;

	for (i = 0; myBuff[i] != '\0'; i++)
	{
	if (myBuff[i] == '#' && myBuff[i - 1] == ' ' && myBuff[i + 1] == ' ')
	{
		myBuff[i] = '\0';
	}
	}
}
