#include <stdio.h>
int main(){
    int a;
    int b;
    int c;
    int sum=0;
    scanf("%d",&a);
    scanf("%d",&b);
for(int i=0;i<b;i++){
    scanf("%d",&c);
    if(c%2==0){
        sum=sum+c/2;
    }
    else{
        
        sum=sum+(c+1)/2;
    }
}        
if (sum>=a){

    printf("%s","YES");
}
else{

    printf("%s","NO");
}
}