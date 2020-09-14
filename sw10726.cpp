#include <iostream>
#include <vector>
#include <queue>
using namespace std;





int solve(int a, int b)
{
    int flag = 0;
    for (int i = 0; i < a; ++i)
    {
        if((b & (1 << i)) >> i) continue;
        else 
        {
           flag = 1;
           break;
        }
    }
    return flag;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n,a,b;

    cin>>n;

    for (int i = 1; i <= n; ++i)
    {
        cin>>a>>b;
        int ans = solve(a,b);
        if(ans==0)cout<<"#"<<i<<" ON\n";
        else cout<<"#"<<i<<" OFF\n";
    }
    return 0;
}