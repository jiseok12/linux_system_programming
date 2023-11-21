#include<netdb.h>
#include<stdio.h>

int main(){
    struct hostent *hent;

    sethostent(0); 
    
    //ip와 host 명을 가지고 온다
    while ((hent = gethostent()) != NULL){
        printf("Name =%s\n", hent->h_name);
        for(int i = 0;i<5;i++){
            
        }
        printf("list = %o\n", *(hent)->h_addr_list[0]);
    }
        

    endhostent();
}