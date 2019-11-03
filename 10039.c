#include <stdio.h>
int main(){
    int score[5];
    int sum=0;
    int b;
    for(int i=0;i<5;i++){
        scanf("%d",&b);
        if(b<40){
            b=40;
        }
        score[i]=b;
    }
    for(int i=0;i<5;i++){
        sum=score[i]+sum;
    }
    printf("%d",sum/5);
}