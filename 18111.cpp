#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n,m,b;
long long low;
long long high;
long long ans;
long long ex =-1;
int arr[501][501];

int bfs(long long mid)
{
    int hcnt = 0;
    int lcnt = 0;
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j]>mid)
            {
                hcnt = hcnt + (arr[i][j] - mid); 
            }
            else if(arr[i][j]<mid)
            {
                lcnt = lcnt + (mid - arr[i][j]);
            }
        }
    }
    if(lcnt>b+hcnt) return -1;
    total = lcnt+ (hcnt*2);
    if(ex==-1||ex>=total)
    {
        ex = total;
        ans = mid;
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m>>b;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
            if(i==0&&j==0)
            {
                low = arr[i][j];
                high = arr[i][j];
            }
            else
            {
                if(low>arr[i][j]) low = arr[i][j];
                if(high<arr[i][j]) high = arr[i][j];
            }
        }
    }
    for(int i = low; i <= high; i++)
    {
        if(bfs(i)==-1)break;
    }
    cout<<ex<<" "<<ans<<"\n";
}  