#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int w, h;
int arr[51][51];
int chk[51][51];

void play(int i, int j){
	stack< pair<int,int> > stk;
	stk.push(make_pair(i,j));
	while(!stk.empty()){
		int a = stk.top().first;
		int b = stk.top().second;
		chk[a][b] = 1;
		stk.pop();
		if(a-1>=0&&b-1>=0&&arr[a-1][b-1]==1&&chk[a-1][b-1]==0){
			stk.push(make_pair(a-1,b-1));
		}
		if(a-1>=0&&arr[a-1][b]==1&&chk[a-1][b]==0){
			stk.push(make_pair(a-1,b));
		}
		if(a-1>=0&&b+1<w&&arr[a-1][b+1]==1&&chk[a-1][b+1]==0){
			stk.push(make_pair(a-1,b+1));
		}
		if(b-1>=0&&arr[a][b-1]==1&&chk[a][b-1]==0){
			stk.push(make_pair(a,b-1));
		}
		if(b+1<w&&arr[a][b+1]==1&&chk[a][b+1]==0){
			stk.push(make_pair(a,b+1));
		}
		if(b-1>=0&&a+1<h&&arr[a+1][b-1]==1&&chk[a+1][b-1]==0){
			stk.push(make_pair(a+1,b-1));
		}
		if(a+1<h&&arr[a+1][b]==1&&chk[a+1][b]==0){
			stk.push(make_pair(a+1,b));
		}
		if(a+1<h&&b+1<w&&arr[a+1][b+1]==1&&chk[a+1][b+1]==0){
			stk.push(make_pair(a+1,b+1));
		}
	}
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int cnt = 0;
    while(1)
    {
	    cin>>w>>h;
	    if(w==0&&h==0) break;
	    for(int i = 0; i < h; i++){
	    	for(int j = 0; j < w; j++){
	    		cin>>arr[i][j];
	    	}
	    }
	    for(int i = 0; i < h; i++){
	    	for(int j = 0; j < w; j++){
	    		if(arr[i][j]==1&&chk[i][j]==0){
	    			play(i,j);
	    			cnt++;
	    		}
	    	}
	    }
	    for(int i = 0; i < h; i++){
	    	for(int j = 0; j < w; j++){
	    		arr[i][j] = 0;
	    		chk[i][j] = 0;
	    	}
	    }
	    cout<<cnt<<"\n";
	    cnt = 0;
	}
	return 0;
}