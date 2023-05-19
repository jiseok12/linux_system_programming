#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

extern int errno;

int main(){
    FILE *fp;

    if((fp=fopen("test.txt", "r"))==NULL){ //오류가 발생하는 라이브러리는 NULL값을 반환한다
        printf("errno=%d\n", errno);        //오류가 발생시 정수를 반환한다
        exit(1);
    }
    fclose(fp);
}
/*
fopen은 파일을 여는 함수 이다
fp=fopen("test.txt","r")
파일에 관한 정보를 fp에 저장하게 된다
fopen은 test.txt 파일이 존재 하지않으면 에러가 발생 하게된다
fopen 라이브러리에서 에러가 발생하면 null값을 반환하게 된다
발생한 에러를 errno가 정수 형태로 오류코드를 반환하게 된다
*/