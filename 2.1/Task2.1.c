#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/wait.h>
#include <string.h>
#define N 5

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("No value!\n");
        exit(EXIT_FAILURE);
    }
    int count = atoi(argv[1]);
    int pipefd[2];
    pid_t pid;
    if (pipe(pipefd))
    {
        fprintf(stderr, "Pipe creation failed!\n");
        exit(EXIT_FAILURE);
    }
switch (pid = fork()) {
	case -1:
		perror("Fork failed!\n");
		exit(EXIT_FAILURE);
	case 0:
        srand(time(NULL));
        close(pipefd[0]);
        for (int i = 0; i < count; i++)
        {
            char a[N];
            snprintf(a, N, "%d", rand() % 100);
            //itoa(rand(), a, 10);
            //sprintf(a, "%d", rand() % 100);
            //sleep(1);
            printf("%s\n", a);
            //write(pipefd[1], a, N);
        }
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
	default:
        char *buf[count];
        close(pipefd[1]);
		for (int i = 0; i < count; i++)
        {
            char *tmp;
            tmp = malloc(N);
            read(pipefd[0], tmp, N);
            tmp[N-1] = '\0';
            buf[i] = tmp;
        }

        close(pipefd[0]);

        wait(NULL);
        
        // Вывод
        for (int i = 0; i < count; i++)
            //sleep(1);
            printf("%s\n", buf[i]);
        
        FILE * fp = fopen("data.txt", "w");
        if (fp)
        {
            for (int i = 0; i < count; i++)
                fprintf(fp, "%s\n", buf[i]);
        }
        fclose(fp);
        exit(EXIT_SUCCESS);
	}
}