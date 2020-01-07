#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long n,cnt = 1,pls=6,ans = 1;
    cin>>n;
    if(n==1)cout<<"1"<<"\n";
    else
    {
        while(n>ans)
        {
            cnt++;
            ans = ans+pls;
            pls = pls + 6;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}  