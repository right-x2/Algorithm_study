#include <stdio.h>
int main(){
    int a=0;
    int b=0;
    int order;
    for(int i=1;i<10;i++){
        scanf("%d",&a);
        if(a>b){
            order=i;
            b=a;
        }
    }
    printf("%d\n",b);
    printf("%d\n",order);
}