#include <stdio.h>
#include <string.h>
void kukudan(int n){
    for(int i=1;i<10;i++){
        printf("%d * %d = %d\n",n,i,i*n);
    }
}
int main(){
    int a;
    scanf("%d",&a);
    kukudan(a);
}