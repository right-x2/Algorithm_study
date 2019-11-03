#include <stdio.h>
#include <string.h>
int main(){
    int test,num;
    int max=0;
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        scanf("%d",&num);
        if (num>max){
            max=num;
        }
    }
    printf("%d",max);
}