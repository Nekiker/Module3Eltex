#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 1;
    int value = atoi(argv[i]);
    int res = value;
    while (argv[i] != NULL)
    {
        value = atoi(argv[i++]);
        if (res < value)
            res = value;
    }

    printf("%d\n", res);
    exit(EXIT_SUCCESS);
}