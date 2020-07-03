#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n,m,t,k;
vector<int>v[1001];
int cost[1001];
int dp[1001];
long long ans;
int bfs()
{
    queue<pair<int,int> >q;
    q.push(make_pair(k,cost[k]));
    while(!q.empty())
    {
        int way = q.front().first;
        long long c = q.front().second;
        q.pop();
        if(v[way].size()==0)
        {
            if(c>ans) ans = c;
            continue;
        }
        for (int i = 0; i < v[way].size(); ++i)
        {
            if(dp[v[way][i]]<c+cost[v[way][i]])
            {
                q.push(make_pair(v[way][i],c+cost[v[way][i]]));
                dp[v[way][i]] = c+cost[v[way][i]];
            }
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>n>>m;
        for (int j = 1; j <= n; ++j)
        {
            cin>>cost[j];
        }
        for (int j = 0; j < m; ++j)
        {
            cin>>a>>b;
            v[b].push_back(a);
        }
        cin>>k;
        bfs();
        cout<<ans<<"\n";
        for (int j = 1; j <= n; ++j)
        {
            cost[j] = 0;
            dp[j] = 0;
            v[j].clear();
        }
        ans = 0;
    }
    return 0;
}