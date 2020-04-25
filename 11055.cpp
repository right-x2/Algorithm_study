#include <iostream>
using namespace std;

int n,m;
int arr[1001];
int dp[1001];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    int mx = 0;
    int flag =0;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    dp[0] = arr[0];
    mx = dp[0];
    for (int i = 1; i < n; ++i)
    {
        int temp = 0;
        for (int j = i-1; j >= 0; --j)
        {
            if(arr[i]>arr[j])
            {
                if(dp[j]>temp) temp = dp[j];
            }
        }
        dp[i] = temp + arr[i];
        if(mx<dp[i]) mx = dp[i];
    }
    cout<<mx<<"\n";
    return 0;
}