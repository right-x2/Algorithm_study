#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int cnt = 0;

int dfs(int idx, int sum)
{
    if(sum==m) 
    {
        cnt++;
        return 0;
    }
    for (int i = idx; i < n; ++i)
    {
        dfs(i,sum+1);
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m;
    if(n==m) cout<<1<<"\n";
    else
    {
        for (int i = 0; i < n; ++i)
        {
            dfs(i,n+1);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}  