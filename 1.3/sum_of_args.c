#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 1;
    int sum = 0;
    while (argv[i] != NULL)
        sum += atoi(argv[i++]);
    printf("%d\n", sum);
    exit(EXIT_SUCCESS);
}