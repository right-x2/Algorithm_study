#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> v[101];
stack<int> stk;
int chk[101];
int dfs(int a)
{
    chk[a] = 1;
    int cnt = 0;
    for (int i = 0; i < v[a].size(); ++i)
    {
        stk.push(v[a][i]);
        chk[v[a][i]] = 1;
        cnt++;
    }
    while(!stk.empty())
    {
        int tp = stk.top();
        stk.pop();
        for (int i = 0; i < v[tp].size(); ++i)
        {
            if(chk[v[tp][i]]==0)
            {
                chk[v[tp][i]]=1;
                stk.push(v[tp][i]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<dfs(1)<<"\n";
}  