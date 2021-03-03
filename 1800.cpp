#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int,int> >pv[1001];
int chk[1001];
vector<int> v;
int n,m,k;



int dijkstra(int num)
{
    int cnt = 0;
    priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >,greater<pair< int, pair<int,int> > > >pq;
    pq.push(make_pair(0,make_pair(0,1)));
    while(!pq.empty())
    {
        int p = pq.top().second.second;
        int cost = pq.top().second.first;
        int cnt = pq.top().first;
        pq.pop();
        if(chk[p]==1) continue;
        if(cost>num) cnt++;
        if(cnt>k) continue;
        chk[p] = 1;
        if(p==n) return 1;
        for (int i = 0; i < pv[p].size(); i++)
        {
            if(chk[pv[p][i].second]==0)
            {
                pq.push(make_pair(cnt,make_pair(pv[p][i].first,pv[p][i].second)));
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
    int low = 0;
    int high = 0;
    int ans =-1;
    cin>>n>>m>>k;

    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        pv[a].push_back(make_pair(c,b));
        pv[b].push_back(make_pair(c,a));
        if(c>high) high = c;
    }
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(dijkstra(mid))
        {
            ans = mid;
            high = mid -1;
        }
        else
        {
            low = mid +1;
        }
        for (int i = 0; i <=n; i++)
        {
            chk[i] = 1;
        }
        
    }
    cout<<ans<<"\n";

    return 0;
}