#include <iostream>
using namespace std;

long long dp[101][21];
int arr[101];
int chk[101][21];
int n;
int num;

long long solve(int idx, int sum)
{
    if(idx==n-1)
    {
        if(sum==arr[idx]) return 1;
        else return 0;
    }

    if(chk[idx][sum]==1) return dp[idx][sum];
    else chk[idx][sum] = 1;

    if(sum+arr[idx]<=20) dp[idx][sum] = dp[idx][sum] + solve(idx+1,sum+arr[idx]);
    if(sum-arr[idx]>=0) dp[idx][sum] = dp[idx][sum] + solve(idx+1,sum-arr[idx]);
    

    return dp[idx][sum];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }

    cout<<solve(1,arr[0])<<"\n";
    return 0;
}