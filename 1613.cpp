#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;



int arr[401][401];
int n,m;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int ans = 0;
    int a,b,k;
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

    cin>>k;
    for (int i = 1; i <=k ; ++i)
    {
        cin>>a>>b;
        if(arr[a][b]>0&&arr[a][b]<1000000000)
        {
            cout<<-1<<"\n";
        }
        else if(arr[b][a]>0&&arr[b][a]<1000000000)
        {
            cout<<1<<"\n";
        }
        else
        {
            cout<<0<<"\n";
        }   
    }
    return 0;
}