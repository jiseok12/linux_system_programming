#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int fd, flags;

    fd = open("linux.txt", O_RDWR);
    //linux.txt 파일을 읽기/쓰기 전용으로 연다
    if(fd==-1){
        perror("open");
        exit(1);
    }
    // F_GETEL명령을 설정해 fcntl() 함수를 호출하면 현재 설정된 프래그 값이 리턴된다
    if((flags = fcntl(fd, F_GETFL))==-1){
        perror("fcntl");
        exit(1);
    }

    flags |= O_APPEND;

    if(fcntl(fd, F_SETFL, flags)==-1){
        perror("fcntl");
        exit(1);
    }

    if(write(fd, "Hanbit Academy\n",15) != 15) perror("write");

    close(fd);
    //return 0;
}