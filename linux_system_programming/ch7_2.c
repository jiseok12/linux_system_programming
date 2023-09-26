#include<sys/types.h>
#include<unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    pid_t pid;
    while(1){
        switch(pid = fork()){
            case -1: 
                perror("fork");
                exit(1);
                break;
            case 0 :
                printf("Child process My pid : %d, My Parent's PID:%d\n", (int)getpid(), (int)getppid());
                break;
            default:
                printf("Parent proces -My PID %d, My Parent's PID:%d, My child's PID:%d\n", (int)getpid(), (int)getppid(), (int)pid);
                break;
        }
    }
    printf("Emd of fork\n");
    return 0;
}