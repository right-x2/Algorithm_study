#include <stdio.h>
int main(){
	int a;
	int b;
	int c[100]={};
	int d=0;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",&b);
		if(i==0){
			c[0]=b;
		}
		for(int j=0;j<i;j++){
			if(b==c[j]){
				d++;
				break;
			}
			else{
				c[i]=b;
			}
		}
		
	}printf("%d",d);
}