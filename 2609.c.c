#include <stdio.h>
#include <string.h>
int max(int a,int b){
    int maxn,sum,k=0;
    if (a>b){
        sum=a%b;
        maxn=b;
        k=a;
        while(sum!=0){
            k=maxn;
            maxn=sum;
            sum=k%maxn;
        }
    }
    else{
        sum=b%a;
        maxn=a;
        k=b;
        while(sum!=0){
            k=maxn;
            maxn=sum;
            sum=k%maxn;
        }
    }
    return maxn;
}
int main(){
    int a,b,mm;
    scanf("%d %d",&a,&b);
    mm=max(a,b);
    printf("%d\n",mm);
    printf("%d",a*b/mm);
}   