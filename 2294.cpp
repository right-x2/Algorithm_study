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
    dp[0] = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 1; j <=n; ++j)
        {
            if(v[i]<=j)
            {
                if(dp[j]==0)
                {
                    
                    if(j-v[i]==0) dp[j] =  1;
                    else if(dp[j-v[i]]!=0)
                    {
                        dp[j] = dp[j-v[i]] + 1;
                    }
                }
                else if(dp[j-v[i]]!=0)
                {
                    dp[j] = min(dp[j],dp[j-v[i]] + 1);
                }
                else if(j-v[i]==0)
                {
                    dp[j] = 1;
                }
            }
        }
    }
    if(dp[n]==0) cout<<-1<<"\n";
    else cout<<dp[n];


    return 0;
}