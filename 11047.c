#include <stdio.h>
#include <string.h>
int main(){
    int n,k;
    int count=0;
    int d=0;
    int box[10000]={};
    scanf("%d %d",&n,&k);
    int sum=k;
    for(int i=0;i<n;i++){
        scanf("%d",&box[i]);
    }
    for(int i=0;i<n;i++){
        if(sum>=box[n-1-i]){
            while (sum>=box[n-1-i]){
                sum=sum-box[n-1-i];
                count=count+1;
            }
        }
        if (sum==0){
            break;
        }
    }
    printf("%d",count);
}