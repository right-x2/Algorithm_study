#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long dp[1000001];
int n;
vector<int> v;
vector<int> s;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>num;
        v.push_back(num);
    }
    s = v;
    sort(v.begin(),v.end());
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= v[v.size()-1]; i++)
    {
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
    }
    
    
    for (int i = 0; i < s.size(); i++)
    {
        cout<<dp[s[i]]<<"\n";
    }
    

    return 0;
}