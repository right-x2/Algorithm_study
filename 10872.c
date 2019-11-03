#include <stdio.h>
#include <string.h>
void facto(int a){
    int sum=1;
    for(int i=1;i<=a;i++){
        sum=sum*i;
    }
    printf("%d",sum);
}
int main(){
    int a;
    scanf("%d",&a);
    facto(a);
}