#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    key_t key;
    int shmid;

    key = ftok("shmfile", 1); //키를 생성 한다

    shmid = shmget(key, 1024, IPC_CREAT|0644);
    //공유 메모리를 생성 한다
    if(shmid == -1){
        perror("shmget");
        exit(1);
    }
    return 0;
}