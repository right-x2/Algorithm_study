#include <stdio.h>
int main(){
    int a[8]={1,2,3,4,5,6,7,8};
    int b[8]={8,7,6,5,4,3,2,1};
    int k[8];
    int c=0;
    int count=0;
    int count2=0;
    for(int i=0;i<8;i++){
        scanf("%d",&c);
        k[i]=c;
    }
    for(int i=0;i<8;i++){
        if(k[i]==a[i]){
            count++;
        }
    }
    if(count==8){
        printf("ascending");
    }
    else{
        for(int i=0;i<8;i++){
            if(k[i]==b[i]){
                count2++;
            }
        }
        if(count2==8){
            printf("descending");
        }
        else{
            printf("mixed");
        }
    }
    


}