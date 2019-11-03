#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    int b=1;
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++){
        if (b==10){
            printf("%c\n",a[i]);
            b=0;
        }
        else{
            printf("%c",a[i]);
        }
        b=b+1;
    }
}