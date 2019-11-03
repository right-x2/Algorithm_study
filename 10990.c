#include <stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int b=1;
    if(a==1){
        printf("*");
    }
    for(int i=1;i<a;i++){
        if(i==1){
            for(int j=0;j<a-i;j++){
            printf(" ");
            }
            printf("*");
            printf("\n");
        }
        for(int j=0;j<a-i-1;j++){
            printf(" ");
        }
        printf("*");
        for (int k=0;k<b;k++){
            printf(" ");
            }
        printf("*");
        b=b+2;
        if(i<a-1)
        printf("\n");
        }
}