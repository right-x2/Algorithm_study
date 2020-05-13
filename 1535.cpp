#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int a[21];
int b[21];
int n;
int mx = 0;

int dfs(int idx, int energy, int sum)
{
    if(sum>mx) mx = sum;
    if(idx==n-1)
    {
        return 0;
    }
    for (int i = idx+1; i <n ; ++i)
    {
        if(energy-a[i]>0) dfs(i,energy-a[i],sum+b[i]);
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>b[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if(100-a[i]>0)dfs(i,100-a[i],0+b[i]);
    }
    cout<<mx<<"\n";
    return 0;
}  