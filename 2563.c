#include <stdio.h>
#include <string.h>

int main(){
    int a=0;
    int b[100][100]={};
    scanf("%d",&a);
    int c;
    int d;
    int sum=0;
    for(int i=0;i<a;i++){
        scanf("%d",&c);
        scanf("%d",&d);
        for(int j=c;j<c+10;j++){
            for(int k=d;k<d+10;k++){
                if(b[j][k]!=1){
                    b[j][k]=1;
                    sum=sum+1;
                }

            }
        }  
    }
    printf("%d",sum);  
}