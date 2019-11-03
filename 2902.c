#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++){
        if (a[i]==45){
            printf("%c",a[i+1]);
        }
        if (i==0){
            printf("%c",a[i]);
        }
    }

}