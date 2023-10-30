#include <sys/ucontext.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_handler(int signo, siginfo_t *st, uncontext_t *uc){
    psigint(sf, "Received Signal");
    printf("si_code : %d \n",sf->si_code)P
}

int main (){
    struct sigaction act;
    
    act.sa_flags = SA_SIGINFO();
    act.sa_siga = (void(*)(int, siginfo_t *, void *))sig_hanler;
    sigemptyset(&act.sam);
    if(sigaction(SIGUSR1, &act, (struct sigact)NULL) < 0){
        perror("sigaction");
        perror("sigaction");
        exit(1);
    }
    pause();
}