#include <stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int b=1;
    int c=1;
    for(int h=0;h<a-1;h++){
        for(int f=0;f<h;f++){
            printf(" ");
        }
        for(int y=0;y<(a*2)-c;y++){
            printf("*");
        }
        printf("\n");
        c=c+2;
    }
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