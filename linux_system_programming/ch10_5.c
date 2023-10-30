#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd1[2], fd2[2];
    pid_t pid;
    char buf[257];
    int len, status;

    if(pipe(fd1) == -1){
        perror("pipe");
        exit(1);
    }

    if(pipe(fd2) == -1){
        perror("pipe");
        exit(1);
    }

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0 : //부모 프로세서 쪽
            close(fd1[1]);
            close(fd2[0]);
            len = read(fd1[0], buf, 256); //파이프 내용을 전부 읽어 온다
            write(1, "Child Process:", 15); //printf 대신 사용 저수준에서 사용가능하다
            write(1, buf, len);

            strcpy(buf, "Good\n");
            write(fd2[1], buf, strlen(buf)); // 파이프에 버퍼의 싸이지 만큼 보낸다 chiled -> parents
            break;
        default: //자식 프로세서 쪽
            close(fd1[0]);
            close(fd2[1]);
            write(fd1[1], "Hello\n", 6); //값을 보낸다

            len = read(fd2[0], buf, 256); //값을 읽는다
            write(1, "Parent Process:", 15);
            write(1, buf, len);
            waitpid(pid, &status, 0);
            break;
    }
}