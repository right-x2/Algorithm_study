#include <iostream>
#include <queue>
using namespace std;

int n,m;
int dp[10001];
vector<int> v;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long ans;
    long long n,m;
    cin>>n;
    cin>>m;

    if(n==1||n==5){
        if(n==1) ans = 8*m;
        else ans = 8*m + 4;
    }else{
        ans = m*4;
        if(m%2==1){
            for (int i = 5; i > n; --i)
            {
                ans++;
            }
        } else{
            for (int i = 1; i < n; ++i)
            {
                ans++;
            }            
        }
    }
    cout<<ans<<"\n";

    return 0;
}