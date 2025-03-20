#include <sys/types.h> // for pid_t
#include <unistd.h>    // for fork(), getpid(), and getppid()
#include <sys/wait.h>  // for wait()
#include <stdlib.h>    // for exit()
#include <stdio.h>     // for printf()

// pour print 
void PrintfromTo(int From, int To, int Processus_N)
{
    printf("\n");
    for (int i = From; i <= To; i++)
    {
        printf("%d / ", i);
    }
    printf("\n");
}

//pour print pid number 
void printPidNumber()
{
    printf("\nle pid de fils = %d et le pid de pere = %d\n", getpid(), getppid());
}

//pour cree des processus fils
void Processus_Fils(int From, int To, int Processus_N)
{
    // le  fils :
    pid_t pid; // Correct type for process ID
    pid = fork();
    switch (pid)
    {
    case -1:
        perror("\nErreur !\n");
        exit(1);
        break;
    case 0:
        // dans le processus fils
        printPidNumber();
        PrintfromTo(From, To, Processus_N);
        exit(0);
        break;

    default:
        wait(NULL);
        //codde
        break;
    }
}

int main()
{
    printf("____________________________________________________________________________\n");
    printf("____________________________________________________________________________\n");

    // fils 1:
    Processus_Fils(1,50, 1);

    // fils 2:
    Processus_Fils(51, 100, 2);

    printf("____________________________________________________________________________\n");
    printf("____________________________________________________________________________\n");
    return 0;
}
