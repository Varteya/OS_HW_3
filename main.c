#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    printf("A : %d\n", getpid());
    int B_fork = fork();
    if (B_fork == 0){
        printf("B : %d\n", getpid());
    } else {
        int C_fork = fork();
        if (C_fork == 0){
            printf("C : %d\n", getpid());
            int D_fork = fork();
            if (D_fork == 0){
                printf("D : %d\n", getpid());
            } else {
                int E_fork = fork();
                if (E_fork == 0){
                    printf("E : %d\n", getpid());
                }
            }
        }
    }
    return 0;
}

