#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int alcnt;
int n,m,k;
int len;
string ans;
char arr[101][101];
int chk[101][101][101];
int dp[101][101][101];

int dfs(int y, int x, int cnt)
{
    if(cnt==len)
    {
        return 1;
    }
    if(chk[y][x][cnt]!=0) return dp[y][x][cnt];
    else chk[y][x][cnt] = 1;
    for (int i = 1; i <= k; ++i)
    {
        if(y+i<n&&ans[cnt]==arr[y+i][x])
        {
            dp[y][x][cnt] = dp[y][x][cnt] + dfs(y+i,x,cnt+1);
        }
        if(y-i>=0&&ans[cnt]==arr[y-i][x])
        {
            dp[y][x][cnt] = dp[y][x][cnt] + dfs(y-i,x,cnt+1);
        }
        if(x+i<m&&ans[cnt]==arr[y][x+i])
        {
            dp[y][x][cnt] = dp[y][x][cnt] + dfs(y,x+i,cnt+1);
        }
        if(x-i>=0&&ans[cnt]==arr[y][x-i])
        {
            dp[y][x][cnt] = dp[y][x][cnt] + dfs(y,x-i,cnt+1);
        }
    }
    return dp[y][x][cnt];
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    int sum = 0;
    cin>>n>>m>>k;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = str[j];
        }
    }
    cin>>ans;
    len = ans.length();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(arr[i][j]==ans[0])
            {
                sum = sum + dfs(i,j,1);
            }
        }
    }
    cout<<sum<<"\n";
    return 0;
}   