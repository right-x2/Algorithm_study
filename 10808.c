#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
     int b[26] = {};
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++){
        b[a[i]-'a']=b[a[i]-'a']+1;
    }
    for(int i=0;i<26;i++){
        printf("%d ",b[i]);

    }
}