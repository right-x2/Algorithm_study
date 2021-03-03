#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m,k,a,b;
int arr[16][16];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n>>m>>k;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m;j++)
        {
            cnt++;
            if(cnt==k)
            {
                a = i;
                b = j;
            }
        }
    }
    
    arr[1][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(i==1&&j==1) continue;
            
            if((i>a&&j<b)||(i<a&&j>b)) arr[i][j] = 0;
            else
            {
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
    }
    
    cout<<arr[n][m]<<"\n";
    
    return 0;
}