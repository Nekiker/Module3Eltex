#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 10000

int main(int argc, char *argv[])
{
    int i = 1,
        len = strlen(argv[i++]),
        maxlen = len;
    while (argv[i] != NULL)
    {
        len = strlen(argv[i]);
        char str[len];
        strcpy(str, argv[i]);
        for (int j = 0; j < len; j++)
        {
            if (str[j] == '\n')
            {
                str[j] == '\0';
                len--;
            }
        }
        if (maxlen < len)
            maxlen = len;
        i++;
    }
    printf("%d\n", maxlen);
    exit(EXIT_SUCCESS);
}