#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;



int arr[501][501];
int n,m;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int ans = 0;
    int a,b;
    cin>>n>>m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <=n; ++j)
        {
            if(i==j) continue;
            arr[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b;
        arr[a][b] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if(arr[j][k] > arr[j][i]+arr[i][k]) arr[j][k] = arr[j][i]+arr[i][k];
            }
        }
    }

  
    for (int i = 1; i <=n ; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <=n ; ++j)
        {
            if(arr[i][j]>0&&arr[i][j]<1000000000)
            {
                cnt++;
            }
            if(arr[j][i]>0&&arr[j][i]<1000000000)
            {
                cnt++;
            }
        }
        if(cnt==n-1)   ans++;    
    }
    cout<<ans<<"\n";
    return 0;
}