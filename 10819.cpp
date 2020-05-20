#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

int mx = -10000;
int n;
int chk[9];
vector<int> v;
int dfs(int idx, int cnt, int sum)
{
    if(cnt==n)
    {
        if(sum>mx) mx = sum;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        if(chk[i]==0)
        {
            chk[i] = 1;
            dfs(i,cnt+1,sum + abs((v[idx]-v[i])));
            chk[i] = 0;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    for (int i = 0; i < n; ++i)
    {
        chk[i] = 1;
        dfs(i,1,0);
        chk[i] = 0;
    }
    cout<<mx<<"\n";
}  