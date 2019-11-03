#include <stdio.h>
#include <string.h>

int main(){
    int a[100][100]={};
    int b[100][100]={};
    int f[100][100]={};
    int c;
    int d;
    int e;
    scanf("%d",&c);
    scanf("%d",&d);
    for(int i=0; i<c; i++){
        for(int j=0; j<d; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int k=0; k<c; k++){
        for(int l=0; l<d; l++){
            scanf("%d",&b[k][l]);
        }
    }
    for(int i=0; i<c; i++){
        for(int j=0; j<d; j++){
            if (j==d-1){
                printf("%d\n",a[i][j]+b[i][j]);
            }
            else{
                printf("%d ",a[i][j]+b[i][j]);
            }
        }
    }

       
}