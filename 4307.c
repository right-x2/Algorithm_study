#include <stdio.h>
#include <string.h>
int main(){
    int n,k,a,w;
    scanf("%d",&w);
    for(int j=0;j<w;j++){
        scanf("%d %d",&n,&k);
        int ave=n/2;
        int max=0;
        int min=n;
        int rmin=0;
        for(int i=0;i<k;i++){
            scanf("%d",&a);
            if (n-a>a){
                if(n-a>max){
                    max=n-a;
                }
            }
            else{
                if(a>max){
                    max=a;
                }
            }
            if(ave>a){
                if(min>ave-a){
                    min=ave-a;
                    rmin=a;
                    if(n-rmin<rmin){
                        rmin=n-rmin;
                    }
                }
            }
            else{
                if(min>a-ave){
                    min=a-ave;
                    rmin=a;
                    if(n-rmin<rmin){
                        rmin=n-rmin;
                    }
                }

            }
        }
        if(j==w-1){
            printf("%d %d",rmin,max);
        }
        else{
            printf("%d %d\n",rmin,max);
        }
    }
}