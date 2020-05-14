#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int s,e;
long long chk[10001];
vector< pair<long long,long long> > v[10001];
int n,m;
long long mx;
long long ans;

int bfs(long long mid)
{
    //cout<<mid<<" xmx\n";
    queue<long long> q;
    chk[s] = 1;
    for(int i = 0; i < v[s].size(); i++)
    {
        if(v[s][i].first>=mid)
        {
            if(chk[v[s][i].second]==0)
            {
                chk[v[s][i].second] = 1;
                q.push(v[s][i].second);

            }
        }

    }
    while(!q.empty())
    {
        int idx = q.front();
        if(idx==e) return 1;
        q.pop();
        for (int i = 0; i < v[idx].size(); ++i)
        {
            if(v[idx][i].first>=mid)
            {
                if(chk[v[idx][i].second]==0)
                {
                    chk[v[idx][i].second] = 1;
                    q.push(v[idx][i].second);
                }
            }
        }
    }
    return 0;
}

int search()
{
    long long low = 1;
    long long high = mx;
    while(low<=high)
    {
        long long mid = (low+high)/2;
        int std = bfs(mid);
        //cout<<std<<" "<<mid<<" mdmd\n";
        for (int i = 0; i <= n; ++i)
        {
            chk[i] = 0;
        }
        if(std==1)
        {
            low = mid + 1;
            if(mid>ans) ans = mid;
        }
        else
        {
            high = mid - 1;
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
        int flag = 0;
        for (int j = 0; j < v[a].size(); ++j)
        {
            if(v[a][j].second==b)
            {
                flag = 1;
                if(v[a][j].first<c)
                {
                    v[a][j].first = c;
                    for(int k = 0; k < v[b].size(); k++)
                    {
                        if(v[b][j].second==a) v[b][j].first = c;
                    }
                }
                break;
            }
        }

        if(flag==0)
        {
            v[a].push_back(make_pair(c,b));
            v[b].push_back(make_pair(c,a));         
        }
        if(mx<c) mx = c;
    }

    cin>>s>>e;
    search();
    cout<<ans<<"\n";
    return 0;
}  