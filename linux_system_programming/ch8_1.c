#include<sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(){
    printf("Before SIGCONT Signal to parent. \n");
    kill(getppid(), SIGCONT);

    printf("Before SIQUIT Signal to me\n");
    kill(getpid(), SIGQUIT);

    printf("After SIQUIT Signal \n");
}