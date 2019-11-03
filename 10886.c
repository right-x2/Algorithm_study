#include <stdio.h>
int main(){
    int a;
    int b;
    int cute=0;
    int ncute=0;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&b);
        if(b==1){
            cute++;
        }
        else if(b==0){
            ncute++;
        }
    }
    if(cute>ncute){
        printf("Junhee is cute!");
    }
    else{
        printf("Junhee is not cute!");
    }
}