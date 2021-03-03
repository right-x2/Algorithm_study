#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int INF = 987654321;
int chk[1000001];
int dp(int idx)
{
    if(chk[idx]!=0) return chk[idx];
    if(idx==1) return 0;
    int a = INF;
    int b = INF;
    int c = INF;
    if(idx%3==0) a = dp(idx/3)+1;
    if(idx%2==0) b = dp(idx/2)+1;
    c = dp(idx-1)+1;

    int ans = min(a,b);
    ans = min(ans,c);
    chk[idx] = ans;
    return ans;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;

    cout<<dp(n)<<"\n";
    return 0;
}