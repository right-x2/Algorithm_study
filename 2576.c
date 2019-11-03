#include <stdio.h>
int main(){
    int sum=0;
    int a=0;
    int b=1000;
    for(int i=0; i<7;i++){
    scanf("%d",&a);
    if (a%2!=0){
        sum=sum+a;
        if(a<b){
            b=a;
            }
        }
    }
    if(sum==0){
                b=-1;
                printf("%d\n",b);
            }
    else{
        printf("%d\n",sum);
        printf("%d\n",b);
    }
    
}