#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

float calcS(char *arg)
{
    float side = atof(arg);
    float s = side * side;
    printf("S = %g\n", s);
}

int main(int argc, char *argv[])
{
    int lengthOfTasks = argc / 2;
	pid_t pid;
	int rv;
    if (argc == 1)
    {
        printf("No values!\n");
        exit(EXIT_SUCCESS);
    }
    if (argc == 2)
    {
        calcS(argv[1]);
        exit(EXIT_SUCCESS);
    }
	switch (pid = fork()) {
	case -1:
		perror("fork");
		exit(EXIT_FAILURE);
	case 0:
		for (int i = 1; i < lengthOfTasks; i++)
            calcS(argv[i]);
		exit(EXIT_SUCCESS);

	default:
		for (int i = lengthOfTasks; i < argc; i++)
            calcS(argv[i]);
        wait(&rv);
	}
	exit(EXIT_SUCCESS);
}