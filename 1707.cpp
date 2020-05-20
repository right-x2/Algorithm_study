#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int flag;
vector<int> v[20001];
int chk[20001];
int dfs(int idx,int pre, int cnt)
{
    for (int i = 0; i < v[idx].size(); ++i)
    {
        if(v[idx][i]!=pre&&chk[v[idx][i]]==0&&flag==0)
        {
            chk[v[idx][i]] = cnt+1;
            dfs(v[idx][i],idx,cnt+1);
        }
        else if(v[idx][i]!=pre&&chk[v[idx][i]]!=0&&(chk[idx]-chk[v[idx][i]])%2==0)
        {
            flag = 1;
            return 0;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t,a,b;

    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>n>>m;
        for (int j = 0; j < m; ++j)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int j = 1; j <=n; j++)
        {
            if(chk[j]==0&&v[j].size()>0)
            {
                chk[j] = 1;
                dfs(j,0,1);              
            }
        }
        if(flag==0)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
        flag = 0;
        for (int j= 1; j <= n; ++j)
        {
            chk[j] = 0;
            v[j].clear();
        }
    }

}  