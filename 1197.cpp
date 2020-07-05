#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
long long ans = 0;
int n,m;
long long arr[10001];
int chk[10001];
vector<pair<int,long long> >v[10001];

int bfs()
{
    priority_queue<pair<int,int> >q;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        int nde = q.top().second;
        q.pop();
        for (int i = 0; i < v[nde].size(); ++i)
        {
            if(v[nde][i].second<arr[v[nde][i].first])
            {
                if(chk[v[nde][i].first]==0)
                {
                   q.push(make_pair(v[nde][i].second,v[nde][i].first));
                   chk[v[nde][i].first] = 1;
                }
                arr[v[nde][i].first] = v[nde][i].second;
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
    long long c;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = 1000001;
    }
    arr[1] = 0;
    chk[1] = 1;
    bfs();
    for (int i = 1; i <= n; ++i)
    {
        ans = ans + arr[i];
    }
    cout<<ans<<"\n";
    return 0;
}