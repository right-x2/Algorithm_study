#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int s,e;
int chk[1001];
vector<pair<int,int> >v[1001]; 
long long ans = 0;

int bfs()
{
    queue<pair<int,int> > q;
    for (int i = 0; i < v[s].size(); ++i)
    {
        q.push(make_pair(v[s][i].first,v[s][i].second));
    }
    chk[s] = 1;
    while(!q.empty())
    {
        int cost = q.front().second;
        int idx = q.front().first;
        q.pop();
        if(idx==e)
        {
            ans = cost;
            return 0;
        }
        for (int i = 0; i < v[idx].size(); ++i)
        {
            if(chk[v[idx][i].first]==0)
            {
                chk[v[idx][i].first] = 1;
                q.push(make_pair(v[idx][i].first,v[idx][i].second+cost));
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

    int a,b,c;
    cin>>n>>m;

    for (int i = 0; i < n-1; ++i)
    {
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for (int i = 0; i < m; ++i)
    {
        cin>>s>>e;
        bfs();
        cout<<ans<<"\n";
        for (int j = 1; j <=n ; ++j)
        {
            chk[j] = 0;
        }
        ans = 0;
    }
    return 0;
}