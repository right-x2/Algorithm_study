#include <stdio.h>
int main(){
    int n,l,k,sub1,sub2;
    int sum=0;
    int c1=0;
    int c2=0;
    scanf("%d",&n);
    scanf("%d",&l);
    scanf("%d",&k);
    for(int i=0; i<n; i++){
        scanf("%d",&sub1);
        scanf("%d",&sub2);
        if (l>=sub2){
            sum=sum+140;
            c1=c1+1;
        }
        else if(l>=sub1){
            sum=sum+100;
            c2=c2+1;
        }
    }
    if(c1+c2>k){
        if (c1<=k){
            sum=sum-((c1+c2-k)*100);
        }
        else{
            sum=sum-((c1-k)*140)-(c2*100);
        }
    }
    printf("%d",sum );
}