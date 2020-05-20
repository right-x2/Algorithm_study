#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
long long arr[11][11];
int chk[11];
long long mn = -1;

int dfs(int idx, int s, long long sum, int cnt)
{
    if(cnt==n&&arr[idx][s]!=0)
    {
        sum = sum + arr[idx][s];
        if(mn==-1||mn>sum) mn = sum;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        if(chk[i]==0&&arr[idx][i]!=0)
        {
            chk[i] = 1;
            dfs(i,s,sum+arr[idx][i],cnt+1);
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
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        chk[i] = 1;
        dfs(i,i,0,1);
        chk[i] = 0;
    }
    cout<<mn<<"\n";
}  