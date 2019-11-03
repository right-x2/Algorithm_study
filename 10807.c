#include <stdio.h>
int main(){
    int c[100];
    int a;
    int b;
    int d;
    int count=0;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&b);
        c[i]=b;
    }
    scanf("%d",&d);
    for(int i=0;i<a;i++){
        if(c[i]==d){
            count++;
        }
    }
printf("%d",count);}