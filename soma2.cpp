#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;




int dp[101];
int chk[101];
int n;
vector<int> v;
int num;


int solve(int idx)
{
    if(chk[idx]==1) return 1;
    if(dp[idx]!=0) return dp[idx];
    chk[idx] = 1;
    dp[idx] = solve(idx+v[idx])+1;
    chk[idx] = 0;
    return dp[idx];
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>num;
        v.push_back(num);
    }

    int mx = -1;
    for (int i = 0; i < 2; i++)
    {
        mx = max(mx,solve(i));
    }
    cout<<mx<<"\n";
    return 0;
}  