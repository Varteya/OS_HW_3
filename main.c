#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("A : %d My parent: %d\n", getpid(), getppid());
    int B_fork = fork();
    if (B_fork == 0){
        printf("B : %d My parent: %d\n", getpid(), getppid());
    } else {
        wait(NULL);
        int C_fork = fork();
        if (C_fork == 0){
            printf("C : %d My parent: %d\n", getpid(), getppid());
            int D_fork = fork();
            if (D_fork == 0){
                printf("D : %d My parent: %d\n", getpid(), getppid());
            } else {
                wait(NULL);
                int E_fork = fork();
                if (E_fork == 0){
                    printf("E : %d My parent: %d\n", getpid(), getppid());
                }
            }
            wait(NULL);
        }
    }
    wait(NULL); 
    return 0;
}

