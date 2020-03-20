#include <iostream>
using namespace std;


int arr[1001][1001];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    int xy;
    cin>>n;
    cin>>xy;
    int num = n*n;
    int a = n;
    int cnt = 0;
    int ansy = 0;
    int ansx = 0;
    int y = 0;
    int x = 0;
    int flag = 0;
    while(1){
    	while(y<n){
    		arr[y][x] = num;
    		if(num==xy){
    			ansy = y;
    			ansx = x;
    		}
    		num--;
    		y++;
    		if(num<1){
    			flag = 1;
    			break; 
    		}
    	}
    	if(flag==1)break;
    	y--;
    	x++;
    	while(x<n){
    		arr[y][x] = num;
    		if(num==xy){
    			ansy = y;
    			ansx = x;
    		}
    		num--;
    		x++;
    	}
    	x--;
    	y--;
    	while(y>=cnt){
    		arr[y][x] = num;
    		if(num==xy){
    			ansy = y;
    			ansx = x;
    		}
    		num--;
    		y--;
    	}
    	y++;
    	x--;
    	cnt++;
    	while(x>=cnt){
       		arr[y][x] = num;
       		if(num==xy){
    			ansy = y;
    			ansx = x;
    		}
    		num--;
    		x--; 		
    	}
    	x++;
    	y++;
    	n--;
    }

    for (int i = 0; i < a; i++){
  		for(int j = 0; j < a;j++){
  			cout<<arr[i][j]<<" ";
    	}
    	cout<<""<<"\n";
    }
    cout<<ansy+1<<" "<<ansx+1<<"\n";
	return 0;
}