#include <stdio.h>
#include <string.h>

int main(){
    char v[100][100]={};
    char str[100]="";
    int n;
    int m;
    int u;
    int l;
    int r;
    int d;
    int k=0;
    int h=0;
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d",&u);
    scanf("%d",&l);
    scanf("%d",&r);
    scanf("%d",&d);
    for(int i=0;i<m+u+d;i++){
        for(int j=0;j<n+l+r;j++){
            if((i+j)%2==0){
                v[i][j]='#';
            }
            else{
                v[i][j]='.';
            }
        }

    }
    for(int i=0;i<m+u+d;i++){
        if(i>=u&&i<u+m){
            scanf("%s",str);
            for(int j=0;j<n+l+r;j++){
                if(j>=l&&j<l+n){
                    v[i][j]=str[k];
                    k=k+1;
                }
            }
        k=0;
        }
        
    }

    for(int i=0;i<m+u+d;i++){
        for(int j=0;j<n+l+r;j++){
            printf("%c",v[i][j]);
        }
        printf("\n");

    }

}