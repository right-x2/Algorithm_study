#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<int> v[401];

int chk[401];
int sum[401];
int arr[401][401];
int rechk[401];
int n,m;
int cnt = 0;
int ans = -1;

int solve()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if(arr[i][j]>arr[i][k]+arr[k][j])arr[i][j] = arr[i][k]+arr[k][j];
            }
        }
    }
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;

    cin>>n>>m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            arr[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b>>c;
        v[a].push_back(b);
        arr[a][b] = c;
    }
    solve();


    for (int i = 1; i <= n; ++i)
    {
        if((ans==-1||ans>arr[i][i])&&arr[i][i]!=1000000000) ans = arr[i][i];
    }
    cout<<ans<<"\n";
    return 0;
}