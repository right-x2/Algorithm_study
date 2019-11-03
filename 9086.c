#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    int b=0;
    scanf("%d",&b);
    for(int i=0;i<b;i++){
        scanf("%s",a);
        printf("%c",a[0]);
        printf("%c\n",a[strlen(a)-1]);
    }
}