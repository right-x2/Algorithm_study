#include <iostream>
#include <stack>
using namespace std;

int arr[501][501];
int chk[501][501];
int n,m;


int solve(int y, int x){
	chk[y][x] = 1;
	int cnt = 0;
	stack< pair<int,int> > stk;
	stk.push(make_pair(y,x));
	while(!stk.empty()){
		cnt++;
		int y = stk.top().first;
		int x = stk.top().second;
		stk.pop();
		if(y-1>=0){
			if(arr[y-1][x] == 1&&chk[y-1][x] == 0)
			{
				stk.push(make_pair(y-1,x));
				chk[y-1][x] = 1;
			}
		}
		if(y+1<n){
			if(arr[y+1][x] == 1&&chk[y+1][x] == 0)
			{
				stk.push(make_pair(y+1,x));
				chk[y+1][x] = 1;
			}
		}
		if(x-1>=0){
			if(arr[y][x-1] == 1&&chk[y][x-1] == 0)
			{
				stk.push(make_pair(y,x-1));
				chk[y][x-1] = 1;
			}
		}
		if(x+1<m){
			if(arr[y][x+1] == 1&&chk[y][x+1] == 0) 
			{
				stk.push(make_pair(y,x+1));
				chk[y][x+1] = 1;
			}
		}
	}
	return cnt;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int mx = 0;
    int temp = 0;
    int cnt = 0;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		cin>>arr[i][j];
    	}
    }

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		if(chk[i][j]==0&&arr[i][j]==1){
    			cnt++;
    			temp = solve(i,j);
    			if(mx<temp) mx = temp ;
    		}
    	}
    }
    cout<<cnt<<"\n";
	cout<<mx<<"\n";
    return 0;
}  