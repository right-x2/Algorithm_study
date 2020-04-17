#include <iostream>
#include <queue>
using namespace std;

int arr[10001];
int dp[10001];
int n,m;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;

    for (int i = 1; i <=n ; ++i)
    {
    	cin>>arr[i];
    }


    for (int i = 1; i <= n; ++i)
    {
    	for (int j = 1; j <= i; ++j)
    	{
    		dp[i] = max(dp[i],dp[i-j]+arr[j]);
    	}
    }
    cout<<dp[n];
	return 0;
}