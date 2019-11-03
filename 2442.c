#include <stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int b=1;
    for(int i=1;i<=a;i++){
        for(int j=0;j<a-i;j++){
            printf(" ");
            }
        for (int k=0;k<b;k++){
            printf("*");
            }
        b=b+2;
        if(i<a)
        printf("\n");
        }
}