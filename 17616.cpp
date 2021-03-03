#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
vector<int> v[100001];
vector<int> s[100001];
int chk[100001];


int bfs(int idx)
{
    queue<int> q;
    q.push(idx);
    int ans = 0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i < v[p].size(); i++)
        {
            if(chk[v[p][i]]==0)
            {
                ans++;
                chk[v[p][i]] = 1;
                q.push(v[p][i]);
            }
        }
    }
    return ans;
}

int solve(int idx)
{
    queue<int> q;
    q.push(idx);
    int ans = 0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i < s[p].size(); i++)
        {
            if(chk[s[p][i]]==0)
            {
                ans++;
                chk[s[p][i]] = 1;
                q.push(s[p][i]);
            }
        }
    }
    return ans;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c=0,d=0;
    cin>>n>>m>>k;

    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        s[b].push_back(a);
    }
    c = bfs(k);
    d = solve(k);
    cout<<d+1<<" "<<n-c<<"\n";
    return 0;
}  