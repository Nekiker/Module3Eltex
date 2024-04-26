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
    int stopvalue = 0;
    while (stopvalue < 1000)
    {
        /* Получение команды и её токенизация. */
        printf(">>");
        char cmd[INPUT_STRING];
        fgets(cmd, INPUT_STRING, stdin);
        //printf("%s\n", cmd);
        //return 0;

        char *tokens[AMOUNT_OF_TOKENS];
        int i = 0;
        tokens[i] = strtok(cmd, " ");

        while (tokens[i] != NULL)
            tokens[++i] = strtok(NULL, " ");

        //i = 0;
        //while (tokens[i] != NULL)
        //{
            //printf("%s\n", tokens[i]);
            //i++;
        //}
        //return 0;

        //strcat(tokens[++i], "\0");

        switch (pid = fork())
        {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
            break;
        case 0:
            //char *arggs[] = {"a", "bc", "d", ""};
            if (execv(tokens[0], tokens) == -1)
                printf("Error in execution!\n");
            break;
        default:
            wait(&rv);
            break;
        }
        stopvalue++;
    }
    exit(EXIT_SUCCESS);
}