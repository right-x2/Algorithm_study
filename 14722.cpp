#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int arr[1001][1001];
int dp[3][1001][1001];
int n;

int solve(int y, int x, int idx)
{
    if(y>n||x>n) return 0;
    if(dp[idx][y][x]>0) return dp[idx][y][x];
    int temp = 0;
    if(arr[y][x]==idx) temp = 1;
    if(y==n&&x==n) return temp;
    int nxt = 0;
    if(temp==1) nxt = (idx+1)%3;
    else nxt = idx;
    dp[idx][y][x] = max(solve(y+1,x,nxt),solve(y,x+1,nxt))+temp;
    return dp[idx][y][x];
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n;

    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <=n; j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<solve(1,1,0)<<"\n";

    return 0;
}  