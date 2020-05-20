#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int chk[2001];
vector<int> v[2001];
int n,m;
int flag = 0;
int dfs(int k, int cnt)
{
    if(cnt==5)
    {
        flag = 1;
        return 0;
    }
    for (int i = 0; i < v[k].size(); ++i)
    {
        if(chk[v[k][i]]==0)
        {
            chk[v[k][i]] = 1;
            dfs(v[k][i],cnt+1);
            chk[v[k][i]] = 0;
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
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; ++i)
    {
        if(flag==1) break;
        chk[i] = 1;
        dfs(i,1);
        chk[i] = 0;
    }
    cout<<flag<<"\n";
}  