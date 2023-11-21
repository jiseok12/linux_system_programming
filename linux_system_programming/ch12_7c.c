#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PORTNUM 9000

int main(){
    char buf[256];
    struct sockaddr_in sin, cli;
    int sd;

    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket");
        exit(1);
    }

    memset((char *)&sin, '\0', sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("172.21.110.197");

    if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))){
        perror("connect");
        exit(1);
    }

    if(recv(sd, buf, sizeof(buf), 0)){
        perror("recv");
        exit(1);
    }
    close(sd);
    printf("From Server : %s\n", buf);
}