#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int mx,m;

int force(int n)
{
    int ans,sum = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans = i;
        while(ans>100)
        {
            sum = sum+ans%10;
            ans = ans/10;
        }
        sum = i + sum+(ans/10)+(ans%10);
        if(sum==n) return i;
        sum = 0;
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a;
    cin>>n;
    cout<<force(n)<<"\n";
    return 0;
}  