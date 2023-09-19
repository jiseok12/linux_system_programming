#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int fd;
    char template[] = "/tmp/mytempfile_xxxxx";

    fd = mkstemp(template);
    printf("1. TMP File Name(tmpnam): %s\n", template);
    mkstemp(template);
    printf("2. TMP File Name(tmpnam): %s\n", template);

    
    return 0;
}