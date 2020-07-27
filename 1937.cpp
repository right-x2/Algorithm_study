#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int arr[2501][2501];
int dp[2501][2501];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int n;
int ans = -1;

int dfs(int y, int x)
{
    dp[y][x] = 1;
    int box = 0;
    for (int i = 0; i < 4; ++i)
    {
        if(y+dy[i]<n&&y+dy[i]>=0&&x+dx[i]<n&&x+dx[i]>=0&&arr[y][x]<arr[y+dy[i]][x+dx[i]])
        {
            if(dp[y+dy[i]][x+dx[i]]!=0)
            {
                if(box<dp[y+dy[i]][x+dx[i]]) box = dp[y+dy[i]][x+dx[i]];
            }
            else
            {
                int temp = dfs(y+dy[i],x+dx[i]);
                if(box<temp) box = temp;
            }
        }
    }
    dp[y][x] = dp[y][x] + box;
    return dp[y][x];
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
        for (int j = 0; j < n; ++j)
        {
            if(dp[i][j]==0) 
            {
               dfs(i,j);
               if(dp[i][j]>ans) ans =  dp[i][j];
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}