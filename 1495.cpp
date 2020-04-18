#include <iostream>
#include <queue>
using namespace std;

int arr[1001];
int dp[101][1002];
int n,m,s;
int mx = -1;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>s>>m;
    dp[0][s] = 1;
    for (int i = 1; i <= n; ++i)
    {
    	cin>>arr[i];
    }
    for (int i = 0; i <=n; ++i)
    {
    	for (int j = 0; j <=m ; ++j)
    	{
    		if(dp[i][j]==1){
    			if(j+arr[i+1]<=m) dp[i+1][j+arr[i+1]] = 1;
    			if(j-arr[i+1]>=0) dp[i+1][j-arr[i+1]] = 1;
    		}
    	}
    }
    for (int i = 0; i <=n; ++i)
    {
    	for (int j = 0; j <=m ; ++j)
    	{
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<"\n"<<"";
    }
    int ans = -1;
    for (int i = 0; i <=m; ++i)
    {
    	if(dp[n][i]==1){
    		if(ans<i) ans = i;
    	}
    }

    cout<<ans<<"\n";
	return 0;
}