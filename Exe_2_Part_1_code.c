#include <sys/types.h> // for pid_t
#include <sys/times.h>
#include <unistd.h>   // for fork(), getpid(), and getppid()
#include <sys/wait.h> // for wait()
#include <stdlib.h>   // for exit()
#include <stdio.h>    // for printf()



// pour print pid number
void PrintPidNumber()
{
    printf("\nle pid de fils = %d et le pid de pere = %d\n", getpid(), getppid());
}

void PrintCaracteristiquesDeProcessus()
{
    printf("____________________________________________________________________________\n");
    printf("____________________________________________________________________________\n");

    printf("\nLe numero d identification de l utilisateur : %d", getuid());
    printf("\nLe numero d identification du groupe  : %d", getgid());

    // pour getcwd :
    char *cwd = getcwd(NULL, 0);
    if (cwd != NULL)
    {
        printf("\nle chemin absolu du repertoire de travail courant : %s", cwd);
        free(cwd); // Libérer la mémoire allouée
    }

    // pour nice()
    // on va incremmenter la propriete de cette processus
    nice(-5);

    // pour  la structure tms
    struct tms buffer;
    clock_t start, end;
    start = times(&buffer);
    if (start == (clock_t)-1)
    {
        perror("times() a échoué");
        exit(1);
    }
    sleep(2);

    end = times(&buffer);
    if (end == (clock_t)-1)
    {
        perror("times() a échoué");
        exit(1);
    }
    // Afficher les résultats
    printf("\n\nTemps écoulé : %ld ticks\n", end - start);
    printf("\nTemps CPU utilisateur : %ld ticks\n", buffer.tms_utime);
    printf("\nTemps CPU noyau : %ld ticks\n", buffer.tms_stime);
    printf("\nTemps CPU utilisateur (fils) : %ld ticks\n", buffer.tms_cutime);
    printf("\nTemps CPU noyau (fils) : %ld ticks\n", buffer.tms_cstime);

    printf("____________________________________________________________________________\n");
    printf("____________________________________________________________________________\n");
}

// pour cree des processus fils
void Processus_Fils()
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
        PrintPidNumber();
        PrintCaracteristiquesDeProcessus();
        exit(0);
        break;

    default:
        wait(NULL);
        // codde
        break;
    }
}

int main()
{
    printf("\nCaracteristiques De Processus fils : \n");
    Processus_Fils();
    printf("\nCaracteristiques De Processus pere : \n");
    PrintPidNumber();
    PrintCaracteristiquesDeProcessus();
    return 0;
}
