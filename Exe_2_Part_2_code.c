
#include <sys/types.h> // for pid_t
#include <sys/times.h>
#include <unistd.h>   // for fork(), getpid(), and getppid()
#include <sys/wait.h> // for wait()
#include <stdlib.h>   // for exit()
#include <stdio.h>    // for printf()
// variable global :
int n = 1000;

// pour print pid number
void PrintPidNumber()
{
    printf("\nle pid de fils = %d et le pid de pere = %d\n", getpid(), getppid());
}

int main()
{
    // variable local
    int m = 1000;
    pid_t pid;
    pid = fork();
    switch (pid)
    {
    case -1:
        perror("\nErreur !\n");
        exit(1);
        break;
    case 0:
        printf("____________________________________________________________________________\n");
        printf("____________________________________________________________________________\n");
        // dans le processus fils
        PrintPidNumber();
        printf("\nLe Fils :\n");
        int *p = &m;
        int *q = &n;
        // Avant:
        printf("\nAvant la modification :\n");
        printf("\nla valuer de m = %d ", m);
        printf("\nl adresse de m = %p ", p);
        printf("\nla valuer de n = %d ", n);
        printf("\nl adresse de n = %p ", q);
        // modification :

        m = 12;
        n = 12;

        // Apre :
        printf("\nApre la modification :\n");
        printf("\nla valuer de m = %d ", m);
        printf("\nl adresse de m = %p ", p);
        printf("\nla valuer de n = %d ", n);
        printf("\nl adresse de n = %p\n ", q);
        printf("____________________________________________________________________________\n");
        printf("____________________________________________________________________________\n");
	exit(0);
        break;
    default:
	wait(NULL);
        printf("____________________________________________________________________________\n");
        printf("____________________________________________________________________________\n");

        // dans le processus pere
        PrintPidNumber();
        printf("\nLe pere :\n");
        int *J = &m;
        int *K = &n;
        // Avant:
        printf("\nAvant la modification :\n");
        printf("\nla valuer de m = %d ", m);
        printf("\nl adresse de m = %p ", J);
        printf("\nla valuer de n = %d ", n);
        printf("\nl adresse de n = %p ", K);
        // modification :

        m = 200;
        n = 200;


        // Apre :
        printf("\nApre la modification :\n");
        printf("\nla valuer de m = %d ", m);
        printf("\nl adresse de m = %p ", J);
        printf("\nla valuer de n = %d ", n);
        printf("\nl adresse de n = %p\n", K);
        printf("____________________________________________________________________________\n");
        printf("____________________________________________________________________________\n");
        break;
    }
    return 0;
}
