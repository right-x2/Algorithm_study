#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n,m;
int dis[10001];
int cost[10001];
int chk[10001];
int sum;
int s,e;
vector<pair<int,int> >pv[10001];
vector<pair<int,int> >rv[10001];
queue<int> q;
int cnt = 0;
void solve()
{
    while(!q.empty())
    {
       int tp = q.front();
       q.pop();
       for (int i = 0; i < pv[tp].size(); ++i)
        {
            dis[pv[tp][i].first]--;
            if(cost[pv[tp][i].first]<=pv[tp][i].second + cost[tp])
            {
                cost[pv[tp][i].first] = pv[tp][i].second + cost[tp];
            }
            if(dis[pv[tp][i].first]==0)
            {
                sum = sum + cost[pv[tp][i].first];
                q.push(pv[tp][i].first);
            }
        } 
    }

    q.push(e);
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
       for (int i = 0; i <rv[tp].size(); ++i)
        {
            if(cost[tp]-cost[rv[tp][i].first]==rv[tp][i].second)
            {
                cnt++;
                if(chk[rv[tp][i].first]==0)
                {
                    q.push(rv[tp][i].first);
                    chk[rv[tp][i].first] = 1;
                }
            }
        }         
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    cin>>n;
    cin>>m;

    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b>>c;
        pv[a].push_back(make_pair(b,c));
        rv[b].push_back(make_pair(a,c));
        dis[b]++;
    }
    cin>>s>>e;
    q.push(s);
    solve();

    cout<<cost[n]<<"\n";
    cout<<cnt<<"\n";
    return 0;
}