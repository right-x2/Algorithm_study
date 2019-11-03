#include <stdio.h>
int main(){
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a==b && b==c && a==c){
        e=10000+a*1000;
        printf("%d",e);
    }
    else if(a==b){
        if(a!=c){
            e=1000+a*100;
            printf("%d",e);
        }
    }
    else if(a==c){
        if(a!=b){
            e=1000+a*100;
            printf("%d",e);
        }
      }
    else if(b==c){
        if(a!=b){
            e=1000+b*100;
            printf("%d",e);
        }
    }
    else if(a!=b && b!=c && a!=c){
        if (a>b){
            d=a;
            if(c>d){
                d=c;
            }
        }
        else{
            d=b;
            if(c>d){
                d=c;
            }
        }
        printf("%d",(d)*100);
    }
} 