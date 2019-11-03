#include <stdio.h>
#include <string.h>
void hello(int n){
    for(int i=0;i<n;i++){
        printf("Hello World, Judge %d!\n",i+1);
    }
}
int main(){
    int a;
    scanf("%d",&a);
    hello(a);
}