#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int chk[100001];
vector<pair<int,int> >v[100001]; 
long long mx = -1;
long long ans = 0;

int bfs()
{
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;
    for (int i = 0; i < v[1].size(); ++i)
    {
        q.push(make_pair(v[1][i].second,v[1][i].first));
    }
    chk[1] = 1;
    while(!q.empty())
    {
        int idx = q.top().second;
        int cost = q.top().first;
        q.pop();
        if(chk[idx]==1) continue;
        chk[idx] = 1;
        if(mx<cost) mx = cost;
        ans = ans + cost;
        for (int i = 0; i < v[idx].size(); ++i)
        {
            if(chk[v[idx][i].first]==0)
            {
                q.push(make_pair(v[idx][i].second,v[idx][i].first));
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

    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }

    bfs();
    ans = ans - mx;
    cout<<ans<<"\n";
    return 0;
}