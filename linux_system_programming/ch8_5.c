#include <signal.h>
#include <stdio.h>

int main (){
    sigset_t st;

    sigemptyset(&st);

    sigaddset(&st, SIGINT);
    sigaddset(&st, SIGQUIT);
    sigaddset(&st, SIGKILL);
    if(sigismember(&st, SIGINT)){
        printf("SIGINT has been set. \n");
    }
    if(sigismember(&st, SIGQUIT)){
        printf("SIGQUIT has been set. \n");
    }
    if(sigismember(&st, SIGKILL)){
        printf("SIGKILL has been set. \n");
    }
    printf("** boot pattern: %lx\n", st.__val[0]);
}