#include <stdio.h>
int main(){
    int a;
    int b;
    int c;
    int d;
    int maxj=0;
    int maxh=0;
    int sum=0;
    scanf("%d",&a);
    scanf("%d",&b);
for(int i=0;i<a;i++){
    scanf("%d",&c);
    if(c>maxh){
        maxh=c;
    }
}
for(int i=0;i<b;i++){
    scanf("%d",&d);
    if(d>maxj){
        maxj=d;
    }
}
sum=maxj+maxh;
printf("%d",sum);        
}