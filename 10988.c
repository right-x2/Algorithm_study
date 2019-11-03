#include <stdio.h>
#include <string.h>
int main(){
    char a[101];
    int b=0;
    scanf("%s",a);
    int c=strlen(a)/2;
    
    
    for(int i=0;i<c;i++){
        if (a[i]!=a[strlen(a)-1-i]){
            b=b+1;
            break;
        }
    }
    if(b==1){
        printf("%d",0);
    }
    else{
        printf("%d",1);
    }
}