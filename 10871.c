#include <stdio.h>
int main(){
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    scanf("%d",&a);
    scanf("%d",&b);
    while(c<a){
        scanf("%d",&d);
        if(d<b){
            printf("%d\n",d);
        }
        c++;
    }
}