#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int arr[10001];
long long ans = 0;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long n;
    long long idx = 1;
    long long mod = 0;
    long long k = 0;
    cin>>n;
    n = n - 1;
    while(1)
    {
        if(idx>n) break;
        k = n/idx;
        mod = n%idx;
        ans = ans + (k*(mod/k+1));
        idx = idx + mod/k+1;
        //cout<<idx<<" "<<ans<<"\n";
    }
    ans = ans + idx;
    cout<<ans<<"\n"; 
    return 0;
}