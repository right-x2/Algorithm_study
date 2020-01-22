#include <iostream>

 
using namespace std;

int dp(int n, long long ans)
{
    long long mul = 2;
    int cnt = 1;
    long long to = 3;
    while(cnt<n)
    {
        if(cnt<=3) to = cnt;
        else to = (to *2)%1000000000; 
        ans = ((ans*2) -to)%1000000000;
        cnt++;
        cout<<ans<<" :ans\n";
        cout<<to<<" :to\n";
    }
    return ans;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    long long ans = 9;
    cin>>n;
    cout<<dp(n,ans)<<"\n";
    return 0;
}  