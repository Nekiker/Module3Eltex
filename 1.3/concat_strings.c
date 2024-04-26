#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 10000

int main(int argc, char *argv[])
{
    int i = 1;
    char result[STRING_SIZE];
    while (argv[i] != NULL)
        strcat(result, argv[i++]);
    printf("%s\n", result);
    exit(EXIT_SUCCESS);
}