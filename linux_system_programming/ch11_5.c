#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int shmid, i;
    char *shmaddr, *shmaddr2;

    shmid = shmget(IPC_PRIVATE, 20, IPC_CREAT|0644);
    //공유 메모리 만들기 20byte

    if(shmid == -1){
        perror("shmget");
        exit(1);
    }

    switch (fork())
    {
    case -1:
        perror("fork");
        exit(1);
        break;
    case 0: //자식 프로세서
        shmaddr = (char *)shmat(shmid, (char *)NULL, 0); //공유 공간 만들기
        printf("Child Process ==== \n");
        for (i=0;i<10;i++)
            shmaddr[i] = 'a'+i;
        shmdt((char *)shmaddr); //자녀 프로세서 메모리 공유
        exit(0); // 정상 종료
        break;
    default: //부모 프로세서
        wait(0);
        shmaddr2 = (char *)shmat(shmid, (char *)NULL, 0); 
        //자식프로세서에서 공유 메모리가 사용한 메모리 들고 오기
        printf("Parent Process =======\n"); 
        for(i=0;i<10;i++)
            printf("%c ", shmaddr2[i]);
        printf("\n");
        sleep(5);
        shmdt((char *)shmaddr2);//공유변수를 삭제한다
        shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL);//공유변수 키값을 제거한다
        break;
    }
}