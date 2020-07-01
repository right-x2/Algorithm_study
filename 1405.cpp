#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
double mul[4];
int ct = 0;
int dp[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}; 
int chk[40][40];

long double ans = 0.0;

int dfs(int y, int x,double sum,int cnt)
{
    if(chk[y][x]==1) return 0;
    if(cnt==n)
    {
        ans = ans + sum; 
        return 0;
    }
    chk[y][x]=1;
    for (int i = 0; i < 4; ++i)
    {
        dfs(y+dp[i][0],x+dp[i][1],sum*mul[i],cnt+1);
    }
    chk[y][x]=0;
    
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    double tmp;
    cin>>n;
    for (int i = 0; i < 4; ++i)
    {
        cin>>tmp;
        mul[i] = tmp/100.0;
    }
    dfs(20,20,1.0,0);
    cout.precision(11); cout << fixed;
    cout<<ans<<"\n";
    return 0;
}