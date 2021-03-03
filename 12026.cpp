#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int arr[1001];
int dp[1001];
int n;
int INF = 987654321;
int solve(int idx)
{
    if(idx==n-1) return 0;
    if(dp[idx]>0) return dp[idx];
    int mn = INF;
    for(int i = idx+1; i<n ;i++)
    {
        int mul = (i-idx)*(i-idx);
        if(arr[idx]==1&&arr[i]==2) mn = min(mn,solve(i)+mul);
        else if(arr[idx]==2&&arr[i]==3) mn = min(mn,solve(i)+mul);
        else if(arr[idx]==3&&arr[i]==1) mn = min(mn,solve(i)+mul);
    }

    return dp[idx] = mn;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    
    cin>>n;
    cin>>str;
    for (int i = 0; i < n; i++)
    {
        if(str[i]=='B') arr[i] = 1;
        else if(str[i]=='O') arr[i] = 2;
        else if(str[i]=='J') arr[i] = 3;
    }
    int ans = solve(0);
    if(ans==INF) cout<<-1<<"\n";
    else cout<<ans<<"\n";
    
    return 0;
}  