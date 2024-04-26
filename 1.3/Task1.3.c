#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define INPUT_STRING 200
#define FILENAME_STRING 50
#define AMOUNT_OF_TOKENS 20
#define PROGRAMM_FILES 4

int main(int argc, char *argv[])
{
    char *programmFiles[] = {"sum_of_args", "concat_strings", "max_value", "max_len_of_string"};
    pid_t pid;
    int rv;

    while (1)
    {
        /* Получение команды и её токенизация. */
        printf(">>");
        char cmd[INPUT_STRING];
        fgets(cmd, INPUT_STRING, stdin);

        char *tokens[AMOUNT_OF_TOKENS];
        int i = 0;
        tokens[i] = strtok(cmd, " ");

        while (tokens[i] != NULL)
            tokens[++i] = strtok(NULL, " ");

        switch (pid = fork())
        {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0:
            wait(&rv);
        default:
            if (execv(tokens[0], tokens[1]) == -1)
                printf("Error with execution!");
        }
    }
    exit(EXIT_SUCCESS);
}