#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<pair<int,int> > v[801];
vector<int> temp;
int flag = 0;
int chk[801];
int nchk[2];
int n,m;
int ans = -1;
int dfs(int idx, int cost)
{
    if(cost!=-1&&cost>ans) return 0;
    if(idx==n)
    {
        if(nchk[0]==1&&nchk[1]==1)
        {
            if(ans==-1||cost<ans) ans = cost;
        }
        else if(nchk[0]==1)
        {
            ans = ans + 
        }
        else if(nchk[1]==1)
        {
            ans = ans + 
        }
        else if(nchk[0]==0&&nchk[1]==0)
        {

        }
        return 0;
    }
    for (int i = 0; i < v[idx].size(); ++i)
    {
        if(chk[v[idx][i].first]==0)
        {
            chk[v[idx][i].first] = 1;
            if(v[idx][i].first==temp[0])nchk[0] = 1;
            else if(v[idx][i].first==temp[1])nchk[1] = 1;
            dfs(v[idx][i].first,cost+v[idx][i].second);
            if(v[idx][i].first==temp[0])nchk[0] = 0;
            else if(v[idx][i].first==temp[1])nchk[1] = 0;
            chk[v[idx][i].first] = 0;
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
    for (int i = 0; i < 2; ++i)
    {
        cin>>a;
        temp.push_back(a);
    }
    chk[1] = 1;
    return 0;
}