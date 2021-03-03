#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int dp[20001];
int chk[20001];
int INF = 987654321;
vector<int> v;
int n,m;
int solve(int idx)
{
    if(idx==0) return 0;
    if(dp[idx]>0) return dp[idx];
    int mn = INF;
    for(int i = v.size()-1; i>=0; i--)
    {
        if(idx-v[i]<0) continue;
        mn = min(mn,solve(idx-v[i]));
    }
    return dp[idx] = mn+1;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    int num;
    cin>>n>>m;

    for(int i = 0; i < m; i++)
    {
        cin>>num;
        int len = v.size();
        for(int j = 0;j< len; j++)
        {
            if(chk[num+v[j]]==0)
            {
                chk[num+v[j]] = 1;
                v.push_back(num+v[j]);
            }
        }
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    cout<<solve(n)<<"\n";

    return 0;
}