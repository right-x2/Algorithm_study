#include <stdio.h>
int main(){
    int c[30];
    int k[2];
    int b;
    int d=0;
    int count=0;
    int max=0;
    int min=0;
    for(int i=0;i<28;i++){
        scanf("%d",&b);
        c[i]=b;
    }
    for(int i=1;i<31;i++){
        for(int j=0;j<28;j++){
            if(c[j]==i){
                count++;
            }
        }
        if(count==0){
            k[d]=i;
            d++;
        }
        count=0;
    }
    if(k[0]>k[1]){
        max=k[0];
        min=k[1];
    }
    else{
        min=k[0];
        max=k[1];
    }
    printf("%d",min);
    printf("\n%d",max);
}