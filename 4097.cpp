#include <iostream>

using namespace std;

int n;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    while(1)
    {
        cin>>n;
        if(n==0) break;
        int ans = -987654321;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>num;
            sum = sum + num;
            ans = max(sum,ans);
            sum = max(sum,0);
        }
        cout<<ans<<"\n";
    }
    return 0;
}