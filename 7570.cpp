#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[1000001];


int n;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n;
    int a;
    int mx =0;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        dp[a] = dp[a-1]+1;
        mx = max(dp[a],mx);
    }

    cout<<n-mx<<"\n";
    
    return 0;
}