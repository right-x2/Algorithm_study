#include <iostream>
#include <queue>
using namespace std;

long long n,m;
long long arr[101][101];
long long chk[101][101];
long long dp[101][101];

long long solve(int a, int b)
{
	if(a==n-1&&b==n-1) return 1;
	if(arr[a][b]==0) return 0;

	if(chk[a][b]==1) return dp[a][b];
	else chk[a][b] = 1;

	if(a+arr[a][b]<n) dp[a][b] = dp[a][b]+ solve(a+arr[a][b],b);
	if(b+arr[a][b]<n) dp[a][b] = dp[a][b]+ solve(a,b+arr[a][b]);

	return dp[a][b];
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		cin>>arr[i][j];
    	}
    }
    solve(0,0);
    cout<<dp[0][0]<<"\n";

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		cout<<chk[i][j]<<" ";
    	}
    	cout<<"\n"<<"";
    }
 
	return 0;
}