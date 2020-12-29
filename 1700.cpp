#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[101][101];
int cidx[101];
int pos[101];
int n,m;
int ans;
vector<int> v;

int solve(int idx, int cnt)
{
    int j = -1;
    int mn = -1;
    int flag = 0;
    if(idx==m)
    {
        ans = cnt;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        if(pos[i]==v[idx])
        {
            cidx[v[idx]]++;
            solve(idx+1,cnt);
            return 0;
        }
        if(flag!=1&&pos[i]==0) 
        {
            flag = 1;
            j = i;
        }
        else if(flag==0&&arr[pos[i]][cidx[pos[i]]]==0) 
        {
            flag = 2;
            j = i;
        }
        else if(flag==0&&arr[pos[i]][cidx[pos[i]]]>mn)
        {
            mn = arr[pos[i]][cidx[pos[i]]];
            j = i;
        }

    }
    pos[j] = v[idx];
    cidx[pos[j]]++;
    if(flag==1) solve(idx+1,cnt);
    else solve(idx+1,cnt+1);
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int a;

    cin>>n>>m;
    ans = m;
    for (int i = 1; i <= m; ++i)
    {
        cin>>a;
        v.push_back(a);
        arr[a][cidx[a]] = i;
        cidx[a]++;
    }

    for (int i = 0; i < 101; ++i)
    {
        cidx[i] = 0;
    }

    solve(0,0);

    cout<<ans<<"\n";
    return 0;
}