#include <iostream>
#include <stack>
using namespace std;

int arr[501][501];
int chk[501][501];
int dp[501][501];
int n,m;


int solve(int y, int x){
		if(y==n-1&&x==m-1){
			return 1;
		}
		if(chk[y][x]==1) return dp[y][x];
		else chk[y][x]=1;

		if(y-1>=0){
			if(arr[y][x]>arr[y-1][x])
			{
				
				dp[y][x] = dp[y][x] + solve(y-1,x);
			}
		}
		if(y+1<n){
			if(arr[y][x]>arr[y+1][x])
			{
				
				dp[y][x] = dp[y][x] + solve(y+1,x);
			}
		}
		if(x-1>=0){
			if(arr[y][x]>arr[y][x-1])
			{
				
				dp[y][x] = dp[y][x] + solve(y,x-1);

			}
		}
		if(x+1<m){
			if(arr[y][x]>arr[y][x+1]) 
			{
				
				dp[y][x] = dp[y][x] + solve(y,x+1);
			}
		}
		return dp[y][x];
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		cin>>arr[i][j];
    	}
    }

    
    cout<<solve(0,0)<<"\n";

    return 0;
}  