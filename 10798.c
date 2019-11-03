#include <stdio.h>
#include <string.h>

int main(){
    char b[5][16]={};
    for(int i=0;i<5;i++){

        scanf("%s",b[i]);

    }
    for(int i=0;i<16;i++){
        for (int j=0; j<5;j++){
            if (b[j][i]!='\0'){
                printf("%c",b[j][i]);
            }
            
        }
    }
}   