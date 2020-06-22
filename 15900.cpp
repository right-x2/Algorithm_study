#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


long long cnt;
vector<int> v[500001];
int chk[500001];

int dfs(int idx,long long d)
{
    if(v[idx].size()==1)
    {
        cnt = cnt + d;
        return 0;
    }
    for (int i = 0; i < v[idx].size(); ++i)
    {
        if(chk[v[idx][i]]==0)
        {
            chk[v[idx][i]] = 1;
            dfs(v[idx][i],d+1);
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    int a,b;
    int p;
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    chk[1] = 1;
    for (int i = 0; i < v[1].size() ; ++i)
    {
        if(chk[v[1][i]]==0)
        {
            chk[v[1][i]] = 1;
            dfs(v[1][i],1);          
        }
    }
    if(cnt%2==0) cout<<"No"<<"\n";
    else cout<<"Yes"<<"\n";
    return 0;
}