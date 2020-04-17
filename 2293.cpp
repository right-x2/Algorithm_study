#include <iostream>
#include <queue>
using namespace std;

int n,m;
int dp[10001];
vector<int> v;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    cin>>m>>n;

    for (int i = 0; i <m ; ++i)
    {
    	cin>>a;
    	v.push_back(a);
    }
    dp[0] = 1;
    for (int i = 0; i < v.size(); ++i)
    {
    	for (int j = 1; j <=n; ++j)
    	{
    		if(v[i]<=j)
    		{
	    		dp[j] = dp[j-v[i]] + dp[j];
    		}
    	}
    }
    cout<<dp[n];
	return 0;
}