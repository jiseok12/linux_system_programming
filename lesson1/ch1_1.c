#include<stdio.h>
#include<unistd.h>
#include<errno.h>

extern int errno;

int main(){
    if(access("test.txt", F_OK)==-1){   //에러 발생 여부를 조사한다
        printf("errno=%d\n",errno);     //에러 발생시 에러 번호를 보여준다
                                        //에러는 정수 형태로 나오게 된다
        return 0;
    }
    printf("성공했어요!!\n");
}