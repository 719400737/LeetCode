#include<stdio.h>
#include<string.h>

void helper(char* s){
    while(*s!='\0'){
        int res=0;//16进制的数
        if(*s>='0' && *s<='9')
            res+=*s-'0';
        else
            res+=(*s-'A')+10;
        s++;
        res*=16;
        if(*s>='0' && *s<='9')
            res+=*s-'0';
        else
            res+=(*s-'A')+10;
        s++;
        char temp;
        if(res>=48 && res<=57);{
            temp=res-48+'0';
        }
        if(res>=65 && res<=90){
            temp=res-65+'A';
        }
        if(res>=97){
            temp=res-97+'a';
        }
        printf("%c",temp);
    }
    printf("\n");
    
}

int main(){

    char s[1001];
    scanf("%s",&s);
    helper(s);

}