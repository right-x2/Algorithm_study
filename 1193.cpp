#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long n;
    int a = 1 , b = 1,c=1,pls=1,flag = 0;
    cin>>n;
    while(c<n)
    {
        c = c + 1;
        b++;
        if(c==n) break;
        c = c + pls;
        if(flag==0) flag = 1;
        else flag = 0;
        pls++;
    }
    while(c>n)
    {
        b--;
        a++;
        c--;
    }
    if(flag==0)cout<<a<<"/"<<b<<"\n";
    else cout<<b<<"/"<<a<<"\n";
    return 0;
    
}  