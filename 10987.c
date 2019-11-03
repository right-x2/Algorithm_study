#include <stdio.h>
#include <string.h>
void k(char a[]){
    int count=0;
    for(int i=0;i<strlen(a);i++){
        if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
            count=count+1;
        }
    }
    printf("%d",count);
}
int main(){
    char a[100];
    scanf("%s",a);
    k(a);
}   