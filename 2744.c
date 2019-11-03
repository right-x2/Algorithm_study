#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    int b=1;
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++){
        if (a[i]>='A' & a[i]<='Z'){
            a[i]=a[i]+32;
        }
        else if(a[i]>='a' & a[i]<='z'){
            a[i]=a[i]-32;
        }
    }
    printf("%s",a);
}