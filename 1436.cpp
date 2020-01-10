#include <iostream>
#include <vector>

using namespace std;

int chk(int n)
{
    int ct = 0;
    if(n%10==6) ct++;
    n = n/10;
    while(n>10)
    {
        if(ct==3) return 1;
        if(n%10==6) ct++;
        else ct = 0;
        n = n/10;
    }
    if(n==6)ct++;
    if(ct>2) return 1;
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,ans = 665,cnt = 0;
    cin>>n;
    while(cnt<n)
    {
        ans++;
        if(chk(ans)) cnt++;
    }
    cout<<ans<<"\n";
    return 0;
}  